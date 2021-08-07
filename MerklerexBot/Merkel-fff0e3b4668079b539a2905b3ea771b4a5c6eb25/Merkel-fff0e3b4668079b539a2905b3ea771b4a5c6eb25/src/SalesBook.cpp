#include "../include/SalesBook.h"
#include <iostream>


SalesBook::SalesBook(std::string filename)
{
    Sales = CSVReader::readCSV(filename);
}



void SalesBook::insertSale(OrderBookEntry& sale)
{
    Sales.push_back(sale);
    std::sort(Sales.begin(), Sales.end(), OrderBookEntry::compareByTimestamp);
    std::cout << '\n';
    logSale(sale);
    
}

/** Get Sales filtered by type*/
std::vector<OrderBookEntry> SalesBook::getSales(std::string& prod)
{

    std::vector<OrderBookEntry> sales_sub;
    for (OrderBookEntry& e : Sales)
    {
        if(e.product == prod)
        {
            sales_sub.push_back(e); 
        }       
    }
    return sales_sub;

}

/**Gets the earlies time stamp in the order book */
std::string SalesBook::getEarliestTime()
{
    return Sales[0].timestamp;
}

/**Gets the earlies time stamp in the order book */
std::string SalesBook::getLatestTime()
{
    return Sales[Sales.size() - 1].timestamp;
}


std::string SalesBook::getNextTime(std::string timestamp)
{
    std::string next_timestamp = "";
    for (OrderBookEntry& e : Sales)
    {
        if (e.timestamp > timestamp) 
        {
            next_timestamp = e.timestamp;
            break;
        }
    }
    if (next_timestamp == "")
    {
        next_timestamp = Sales[Sales.size() - 1].timestamp;
        std::cout << "This is already the most current time" << '\n';
    }
    return next_timestamp;
}