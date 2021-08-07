#pragma once

#include "OrderBook.h"
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"

class TradingBot {

    public:
        /** constructor with order book */
        TradingBot(MerkelMain& _app);
        
        /** destructor to delete pointers*/
        ~TradingBot();

        /** Call this to initiate bot */
        void Init();

        /** Bot functionality that matches bids to asks and makes sales */
        void RunBotCycle();

        /** Shows predictions for different products*/
        std::map<std::string, std::vector<double>> predictions;


    private:
        
        /** This is the connected application*/
        MerkelMain& app;

        /** Stores a vector of moments for later processing*/
        std::vector<double> GetMomentum(std::vector<OrderBookEntry>& sales);



        /** Bot generates a string that is used to enterAsk/enterBid in MainMerkel*/
        std::string GenerateOrderString(std::string& prod, double& price, double& amount);

        /** Function that generates RSI values for each product */
        double PredictPrices(std::string product);
};