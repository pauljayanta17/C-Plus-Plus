#include "../../include/SettlementBot.h"
#include "../../include/OrderBook.h"
#include "../../include/CSVReader.h"
#include "../../include/common.h"
#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <fstream>


/** constructor for R1A bot */
SettlementBot::SettlementBot(MerkelMain& _app) : app(_app)
{
    
}

/** destructor for pointers */
SettlementBot::~SettlementBot()
{
    
}

/** method that initializes the first bot */
void SettlementBot::Init()
{
    settlementBot_connected = true;
    
    app.sleep(3);

    if(settlementBot_connected){

        
        std::cout << '\n';
        std::cout << "Settlement Bot Connected!" << "\n \n";

        //pause app so reader can read the messages
        app.sleep(2);
        std::cout << "Settlement Bot is attempting to insert 100 ETH,100 BTC, and 100000000 USDT.." << '\n' << '\n';

        std::vector<std::string> product = app.orderBook.getKnownProducts();

        app.wallet.insertCurrency("ETH", 100);
        app.wallet.insertCurrency("USDT", 100000000);
        app.wallet.insertCurrency("BTC", 100);
        
        app.sleep(2);

        if(app.wallet.containsCurrency("ETH", 10) && app.wallet.containsCurrency("USDT",1000))
        {
            std::cout << "Successfully inserted ETH,BTC, and USDT into your wallet!" << "\n \n";
            
        }else {
            std::cout << "Failed to access wallet" << "\n \n";
        }

        app.sleep(2);

        std::cout << "\n \n";
        std::string prod = "BTC/USDT";
        std::cout << "Initiating orders for  >> " << prod << "\n \n";
        
        app.sleep(1);

        std::vector<OrderBookEntry> ask = app.orderBook.getOrders(OrderBookType::ask, prod, app.orderBook.getEarliestTime());
        std::sort(ask.begin(), ask.end(), OrderBookEntry::compareByPriceDesc);
        OrderBookEntry minAskOrder = ask[ask.size() - 1];

        std::string now = getNowTime();
        std::string latestTime = app.orderBook.getLatestTime();
        std::string orderString = minAskOrder.product + "," + std::to_string(minAskOrder.price) + "," + std::to_string(minAskOrder.amount);

        app.sleep(2);

        std::cout << "\n \n";
        std::cout << "Entering following order >> " << "Bid: " << orderString << '\n';
        EnterOrder(OrderBookType::bid, orderString, now);
        
        app.sleep(2);

        std::cout << "\n \n";
        std::cout << "Entering following order >> " << "Ask " << orderString << '\n';
        EnterOrder(OrderBookType::ask, orderString, now);
        

        app.sleep(2);

        std::cout << "\n \n";
        std::cout << "Attempting to settle transaction..." << "\n \n";
        app.sleep(2);


        SettleTransaction(now);
        
    
    }

}

/* Cycle runs on entire order book once for a single time stamp */
void SettlementBot::RunBotCycle(std::map<std::string,std::vector<double>>& predictionsMap)
{
    std::cout << '\n';
    std::cout << "running Settlement Bot cycle...";
    std::cout << '\n';
    app.sleep(2);


    for (auto const& x : predictionsMap)
    {
        std::cout << "\n \n";
        std::cout << "Product >> " << x.first << "\n";

        double first = x.second[0];
        const double len = x.second.size();
        if(len > 1)
        {
            double diff = 0.00;
            double next = x.second[1];
            for(auto const& y : x.second)
            {
                //RSI values for each product   
                next = y;
                diff += (next - first);
                first = y;
            }

            //increasing
            if((diff > 0))
            {
                //bid
                auto askorders = app.orderBook.getOrders(OrderBookType::ask,x.first,app.orderBook.getLatestTime());
                auto lowAsk = app.orderBook.getLowPrice(askorders);
                if(lowAsk < 1.00)
                {
                    auto prod = x.first;
                    auto val = app.salesBook.getSales(prod);
                    lowAsk = val[0].price;
                }

                std::string bidorderString = x.first + "," + std::to_string(lowAsk) + "," + "1.00";
                auto now = getNowTime();
                std::cout << "Entering Order for >> " << x.first << " @ " << now << " \n";
                app.sleep(2);
                EnterOrder(OrderBookType::ask,bidorderString,now);
            }
            //decreasing
            if(diff < 0 && diff < 50)
            {
                //Ask
                if(app.wallet.containsCurrency(x.first, 1)){

                    //Get orders for this product
                    auto orders = app.orderBook.getOrders(OrderBookType::bid,x.first,app.orderBook.getLatestTime());
                    auto highBid = app.orderBook.getHighPrice(orders);
                  

                    if(highBid < 1.00)
                    {
                        auto prod = x.first;
                        auto val = app.salesBook.getSales(prod);
                        highBid = val[0].price;
                    }

                    std::string orderString = x.first + "," + std::to_string(highBid) + "," + "1.00";
                    auto now = getNowTime();
                    std::cout << "Entering Order for >> " << x.first << " @ " << now << " \n";
                    app.sleep(2);
                    EnterOrder(OrderBookType::ask,orderString,now);

                }
            }
        }
        else if(len == 1 && first != 0) {

           if(first > 20)
           {
               //Get orders for this product
                auto orders = app.orderBook.getOrders(OrderBookType::ask,x.first,app.orderBook.getLatestTime());
                auto lowask = app.orderBook.getLowPrice(orders);

                if(lowask < 1.00)
                {
                    auto prod = x.first;
                    auto val = app.salesBook.getSales(prod);
                    lowask = val[0].price;
                }
                std::string orderString = x.first + "," + std::to_string(lowask) + "," + "1.00";

                auto now = getNowTime();
                std::cout << "Entering Order for >> " << x.first << " @ " << now << " \n";
                app.sleep(2);
                EnterOrder(OrderBookType::ask,orderString,now);
           }
        }else{
            std::cout << "No predictions made for >> " << x.first << "\n";
        }
        


    }
    


    std::cout << '\n';
    std::cout << "ending Settlement Bot cycle ...." << '\n';
    
};



void SettlementBot::SettleTransaction(std::string& currentTime)
{
    
    bool breakOut = false;
    for (std::string p : app.orderBook.getKnownProducts())
    {
        if(breakOut)
        {
            break;
        }
        
        std::vector<OrderBookEntry> sales = app.orderBook.matchAsksToBids(p,currentTime);
       

        for (OrderBookEntry& sale : sales)
        {
            
            if (sale.username == "simuser")
            {
                std::cout << "\n \n";
                std::cout << "SOLD > " << sale.product << '\n';
                std::cout << "Price: " << sale.price << ", Amount: " << sale.amount << '\n'; 
                std::cout << "\n \n";

                app.sleep(2);

                // update the wallet
                std::cout << "PROCESSING SALE...." << '\n';
                std::cout << "\n \n";
                
                app.wallet.processSale(sale);
                app.salesBook.insertSale(sale);

                app.sleep(2);

                std::cout << "Successfully processed sale and updated order book" << "\n \n";
                breakOut = true;

                break;
                    
               
            }
        }
        
    }
    std::cout << "\n \n";

}



/** Get time now in milliseconds*/
std::string SettlementBot::getNowTime()
{
    auto date = std::chrono::system_clock::now();
    auto mis = std::chrono::duration_cast<std::chrono::microseconds>(date.time_since_epoch());

    std::time_t time = std::chrono::system_clock::to_time_t(date);
    char *t = std::ctime(&time);
    
    if (t[strlen(t)-1] == '\n') t[strlen(t)-1] = '\0';

    std::stringstream ss;
    ss << t;

    return ss.str();
    
}



/** Function will enter bid/ask accoring to type using proper order string*/
void SettlementBot::EnterOrder(OrderBookType type, std::string& orderString, std::string& timestamp)
{

    std::vector<std::string> tokens = CSVReader::tokenise(orderString, ',');
    time_t now = time(0); //time stamp for now
   
    OrderBookEntry obe = CSVReader::stringsToOBE(
            tokens[1],
            tokens[2], 
            timestamp, 
            tokens[0], 
            type
        );
    obe.username = "simuser";

    if (app.wallet.canFulfillOrder(obe))
    {
        std::cout << "Wallet looks good for user > " << obe.username <<'\n';
        app.orderBook.insertOrder(obe);
    }
    else {
        std::cout << "Wallet has insufficient funds or an error occured for >  ";
        std::cout << "Amount: " << obe.amount << " Price: " << obe.price << " Product: " << obe.product << " Time: " << obe.timestamp << '\n';
    }

    
}