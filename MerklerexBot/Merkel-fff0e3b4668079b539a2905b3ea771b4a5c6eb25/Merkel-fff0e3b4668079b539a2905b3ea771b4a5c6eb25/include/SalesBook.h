#pragma once
#include "OrderBook.h"


class SalesBook : OrderBook
{
    /** Insert friends*/
    friend class TradingBot;
    friend class SettlementBot;
    friend class MerkelMain;

    public:

        /**Constructor */
        SalesBook(std::string filename);

        /** returns the earliest time in the orderbook*/
        std::string getEarliestTime();

        /** Gets the last time logged*/
        std::string getLatestTime();
        
        /** returns the next time after the 
         * sent time in the orderbook  
         * */
        std::string getNextTime(std::string timestamp);

        /** Gets the Sales for a specific product*/
        std::vector<OrderBookEntry> getSales(std::string& prod);

    private:
        /** holds the orders vector**/
        std::vector<OrderBookEntry> Sales;


        void insertSale(OrderBookEntry& sale);
        
        
        


};