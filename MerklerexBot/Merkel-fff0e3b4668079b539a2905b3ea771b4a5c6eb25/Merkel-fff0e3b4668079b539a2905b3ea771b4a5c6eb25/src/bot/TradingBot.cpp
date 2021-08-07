#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <numeric>
#include "../../include/TradingBot.h"
#include "../../include/OrderBook.h"
#include "../../include/CSVReader.h"
#include "../../include/common.h"

/** constructor for R1A bot */
TradingBot::TradingBot(MerkelMain& _app) : app(_app)
{
    auto products = _app.orderBook.getKnownProducts();

    for(auto const& prod : products)
    {
        std::vector<double> p;
        predictions[prod] = p;
    }
}

/** destructor for pointers */
TradingBot::~TradingBot()
{

}


/** method that initializes the first bot */
void TradingBot::Init()
{
    bot1_connected = true;

    
    app.sleep(2);

    if(bot1_connected){
        std::vector<std::string> product = app.orderBook.getKnownProducts();

        std::cout << '\n';
        std::cout << "Trading Bot Connected!" << '\n';

        app.sleep(2);

        if(product.size() > 0)
        {
            std::cout << "\n \n";
            std::cout << "Bot has access to order book with the following products: " << '\n';
            app.sleep(2);
            std::cout << '\n';

            for(const std::string& prod : product)
            {
                std::cout << "Product > " << prod << '\n';
            }

            app.sleep(2);
            std::cout << '\n' << '\n';
            std::cout << "Please run Trading Bot by choosing option 7 from Menu ...." << '\n';
            std::cout << '\n' << '\n';
            app.sleep(2);
        } 
    }
    

}



/** Function that calculates RSI for an order book product*/
double TradingBot::PredictPrices(std::string product)
{    
    double RSI = 0.00;
    std::cout << "\n \n";      
    std::cout << "Predicting Prices for " << product << '\n'; 
    std::vector<OrderBookEntry> sales = app.salesBook.getSales(product);
    std::cout << "\n \n";
    std::cout << "SIZE OF SALES >> " << sales.size() << ", Product >> " << product << "\n";
    app.sleep(2);

    std::sort(sales.begin(),sales.end(), OrderBookEntry::compareByTimestamp);

    if(sales.size() > 0)
    {
        //use get moments
        std::vector<double> moments = GetMomentum(sales);
        double n = moments.size();
        double losses, gains = 0;
        for(double& moment : moments)
        {
            if(moment > 0)gains += moment;
            if(moment < 0)losses += moment;  
        }

        auto ratio = std::abs(gains/losses);
        RSI = (100.00 - (100.00/(1.00 + ratio))); 

    }

   return RSI;

}

/** Gets the momentum values as a vector */
std::vector<double> TradingBot::GetMomentum(std::vector<OrderBookEntry>& sales)
{
    double count = 1;
    double  currentPrice = sales[0].price;
    double nextPrice = 0.0f;
    double momentum = 0.0f;
    double result = 0.0f;
    double ratio = 0.0f;
    std::vector<double> momentumVector;
    for(const OrderBookEntry& entry : sales)
    {

        //Next Price
        nextPrice = entry.price;
        momentum += (nextPrice - currentPrice);

        
        if((int)count % 5 == 0)
        {
            result = momentum/count;

            ratio = (result/sales[0].price)*100;

            //reset momentum
            momentum = 0;
            //Save value
            momentumVector.push_back(ratio);
        }
        currentPrice = nextPrice;
        ++count;

    }

    return momentumVector;
}


/* Cycle runs on entire order book once for a single time stamp */
void TradingBot::RunBotCycle()
{
    std::cout << '\n';
    std::cout << "Running Trading Bot Cycle...";
    app.sleep(2);
    std::cout << '\n';

    std::vector<std::string> products = app.orderBook.getKnownProducts();

    std::cout << "Current OrderBook Time >> " << app.currentTime << '\n';

    app.sleep(2);



    //Make a prediction for each product
    for(const std::string& product : products)
    {
        //Predicts prices for each product
        predictions[product].push_back(PredictPrices(product)); 
        
    }
    
    
    

    std::cout << "\n \n";
    std::cout << "...";
    app.sleep(2);
    std::cout << "ended Trading Bot cycle";
    std::cout << "\n \n";

    app.Toggle_Menu = true;

    
};

/** Function inserts generates a string that can be used as input into enterAsk or enterBid */
std::string TradingBot::GenerateOrderString(std::string& prod, double& price, double& amount)
{
    std::stringstream ss;
    ss << prod<< "," << std::to_string(price) << "," <<std::to_string(amount);
    return ss.str();
}









