#pragma once
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>
#include <map>

class OrderBook
{



    public:

        /** Default Constructor*/
        OrderBook();
        /** construct, reading a csv data file */
        OrderBook(std::string filename);
        /** return vector of all known products in the dataset*/
        std::vector<std::string> getKnownProducts();

        /** returns the earliest time in the orderbook*/
        std::string getEarliestTime();

        /** returns the next time after the 
         * sent time in the orderbook  
         * */
        std::string getNextTime(std::string timestamp);

        /** Gets the last time logged*/
        std::string getLatestTime();

        /** Gets the highest Price from a list of orders*/
        static double getHighPrice(std::vector<OrderBookEntry>& orders);

        /** Gets the lowest Price from a list of orders*/
        static double getLowPrice(std::vector<OrderBookEntry>& orders);

        /** Order Book logs sales through this method*/
        void logSale(OrderBookEntry& entry);

    private:
        friend class TradingBot;
        friend class SettlementBot;
        friend class MerkelMain;
        /** holds the orders vector**/
        std::vector<OrderBookEntry> orders;

        /* Logs Order To CSV*/
        void logOrder(OrderBookEntry& entry);

        /** return vector of Orders according to the sent filters*/
        std::vector<OrderBookEntry> getOrders(OrderBookType type, 
                                              std::string product, 
                                              const std::string& timestamp_);
        
        /** insert Order */
        void insertOrder(OrderBookEntry& order);

        /** Match bids and asks */
        std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);

        
    protected:

        /** Path to sales log*/
        std::string salesLogCsvPath = "/Users/alanjudi/Downloads/MerklerexBot/data/sales_log.csv";

        /** Path to OrderBook CSV file*/
        std::string orderBookCSVPath = "/Users/alanjudi/Downloads/MerklerexBot/data/20200317.csv";

        /* Map from order type to string*/
        std::map<OrderBookType,std::string> EntryType = {
            {OrderBookType::ask, "ask" },
            {OrderBookType::asksale, "asksale"},
            {OrderBookType::bid, "bid"},
            {OrderBookType::bidsale, "bidsale"},
            {OrderBookType::unknown, "unknown"}
        };
};
