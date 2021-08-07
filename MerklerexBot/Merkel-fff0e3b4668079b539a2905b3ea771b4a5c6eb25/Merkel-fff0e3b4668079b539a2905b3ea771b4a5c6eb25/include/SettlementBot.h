#pragma once

#include "OrderBook.h"
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"

class SettlementBot {

    public:
        /** constructor with order book */
        SettlementBot(MerkelMain& _app);
        
        /** destructor to delete pointers*/
        ~SettlementBot();


        /** Call this to initiate bot */
        void Init();

        /** Bot functionality that matches bids to asks and makes sales */
        void RunBotCycle(std::map<std::string,std::vector<double>>& predictionsMap);

        

    private:

        /** Connected App */
        MerkelMain& app;


        /** Enters bid/ask into order book*/
        void EnterOrder(OrderBookType type, std::string& orderString, std::string& timestamp);

        /** Function is used to settle transactinos ... */
        void SettleTransaction(std::string& currentTimeStamp);

        /*Gets the time now*/
        std::string getNowTime();



};