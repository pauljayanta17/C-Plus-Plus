#include "../include/MerkelMain.h"
#include "../include/OrderBookEntry.h"
#include "../include/CSVReader.h"
#include "../include/common.h"
#include <ctime>
#include <iostream>
#include <vector>
#include <future>
#include <fstream>




MerkelMain::MerkelMain()
{

}

void MerkelMain::Init()
{
    currentTime = orderBook.getEarliestTime();
    std::string latestTime = orderBook.getLatestTime();
    do
    {
        gotoNextTimeframe();
        currentTime = orderBook.getNextTime(currentTime);

    }while(latestTime != currentTime);
  
}

void MerkelMain::runCycle()
{
    int input;
    Toggle_Menu = true;

    while(Toggle_Menu)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
      
    }
}


void MerkelMain::printMenu()
{
    // 1 print help
    std::cout << '\n';
    std::cout << "1: Print help " << '\n';
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << '\n';
    // 3 make an offer
    std::cout << "3: Make an offer " << '\n';
    // 4 make a bid 
    std::cout << "4: Make a bid " << '\n';
    // 5 print wallet
    std::cout << "5: Print wallet " << '\n';
    // 6 continue   
    std::cout << "6: Go to next time frame! " << '\n';

    std::cout << "7: Run Trading Bot Cycle" << '\n';

    std::cout << "============== " << '\n';;

    std::cout << "Current time is: " << currentTime << '\n';;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void MerkelMain::printMarketStats()
{
    
    std::cout << "These stats are for time frame >> " << currentTime << "\n \n";
    
    for (std::string const& p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << "\n";
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks seen: " << entries.size() << '\n';
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << '\n';
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << "\n";
        std::vector<OrderBookEntry> entriesBids = orderBook.getOrders(OrderBookType::bid, p, currentTime);
        std::cout << "Bids seen: " << entriesBids.size() << '\n';
        std::cout << "Max bid: " << OrderBook::getHighPrice(entriesBids) << '\n';
        std::cout << "Min bid: " << OrderBook::getLowPrice(entriesBids) << "\n \n";

    }

}


void MerkelMain::enterAsk()
{
    std::cout << "Make an ask - enter the amount: product,price, amount, eg  ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << '\n';
        std::cout << "MerkelMain::enterAsk Bad input! " << input << '\n';
    }
    else {
        try {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2], 
                currentTime, 
                tokens[0], 
                OrderBookType::ask 
            );
            obe.username = "simuser";
            if (wallet.canFulfillOrder(obe))
            {
                std::cout << "Wallet looks good. " << '\n';
                orderBook.insertOrder(obe);
               
            }
            else {
                std::cout << "Wallet has insufficient funds . " << '\n';
            }
        }catch (const std::exception& e)
        {
            std::cout << " MerkelMain::enterAsk Bad input " << '\n';
        }   
    }
}

void MerkelMain::enterBid()
{
    std::cout << "Make an bid - enter the amount: product,price, amount, eg  ETH/BTC,200,0.5" << '\n';
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterBid Bad input! " << input << std::endl;
    }
    else {
        try {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2], 
                currentTime, 
                tokens[0], 
                OrderBookType::bid 
            );
            obe.username = "simuser";

            if (wallet.canFulfillOrder(obe))
            {
                std::cout << "Wallet looks good. " << std::endl;
                orderBook.insertOrder(obe);
            }
            else {
                std::cout << "Wallet has insufficient funds . " << std::endl;
            }
        }catch (const std::exception& e)
        {
            std::cout << " MerkelMain::enterBid Bad input " << std::endl;
        }   
    }
}

void MerkelMain::printWallet()
{
    std::cout << wallet.toString() << std::endl;
}
        
void MerkelMain::gotoNextTimeframe()
{   

    std::cout << "\n \n";
    std::cout << "Current >> " << currentTime << "\n";

    for (std::string p : orderBook.getKnownProducts())
    {
        
        std::vector<OrderBookEntry> sales =  orderBook.matchAsksToBids(p, currentTime);
        

        for (OrderBookEntry& sale : sales)
        {
            
            if (sale.username == "simuser")
            {
                // update the wallet
                std::cout << "\n \n";
                std::cout << "PROCESSING SALE...." << '\n';
                wallet.processSale(sale);
                salesBook.insertSale(sale);
            }
        }
        
    }


    

    currentTime = orderBook.getNextTime(currentTime);
    //std::cout << "Next time frame >> "<< currentTime << "\n \n";
}

/** Puts Merkel main app to sleep for num seconds */
void MerkelMain::sleep(int num)
{
    std::this_thread::sleep_for(std::chrono::seconds(num));

} 
int MerkelMain::getUserOption()
{
    int userOption = 0;
    std::string line;
    std::cout << "Type in 1-7" << std::endl;
    std::getline(std::cin, line);

    try{
        userOption = std::stoi(line);        
    }catch(const std::exception& e)
    {
        std::cout << "An exception occured: " << e.what() << '\n';
    }
    std::cout << '\n';
    std::cout << "You chose: " << userOption << "\n \n" << std::endl;
    return userOption;
}

void MerkelMain::runTradingBot()
{
    Toggle_Menu = false;
}

void MerkelMain::processUserOption(int userOption)
{
    switch(userOption) {
        case 1:
            printHelp();
            break;
        case 2:
            printMarketStats();
            break;
        case 3:
            enterAsk();
            break;
        case 4:
            enterBid();
            break;
        case 5:
            printWallet();
            break;
        case 6:
            gotoNextTimeframe();
            break;
        case 7:
            runTradingBot();
            break;
        default:
            std::cout << "INVALID INPUT, Please choose 1 - 7" << '\n';
    } 
}
