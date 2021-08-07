#pragma once
#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"
#include "SalesBook.h"

class MerkelMain
{
    /** Decalare Trading Bots as friends*/
    friend class TradingBot;
    friend class SettlementBot;
    public:

        
        /** Default Constructor */
        MerkelMain();
        /** Call this to start the sim */
        void Init();

        /** Runs the menu cycle*/
        void runCycle();

        /** Tells us the current time */
        std::string currentTime;

    private: 
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        int getUserOption();
        void processUserOption(int userOption);
        
        /** Toggle Menu*/
        bool Toggle_Menu = false;

        /** Function that runs the trading Bot */
        void runTradingBot();

        /** Path to OrderBook CSV file*/
        std::string orderBookCSVPath = "/Users/alanjudi/Downloads/MerklerexBot/data/20200317.csv";

        /** Path to sales log*/
        std::string salesLogCsvPath = "/Users/alanjudi/Downloads/MerklerexBot/data/sales_log.csv";

        /** This is the Order book */
        OrderBook orderBook{orderBookCSVPath};

        /** This is the Sales book*/
        SalesBook salesBook{salesLogCsvPath};

        /** Application will sleep so user can read messages */
        void sleep(int num);   
        
        /** This is the wallet */
        Wallet wallet;

};
