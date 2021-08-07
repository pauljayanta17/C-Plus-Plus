#include "../include/OrderBook.h"
#include "../include/CSVReader.h"
#include <algorithm>
#include <iostream>
#include <fstream>



/** Default Constructor*/
OrderBook::OrderBook()
{
    
}

/** construct, reading a csv data file */
OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}

/** return vector of all know products in the dataset*/
std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> products;

    std::map<std::string,bool> prodMap;

    for (OrderBookEntry& e : orders)
    {
        prodMap[e.product] = true;
    }
    
    // now flatten the map to a vector of strings
    for (auto const& e : prodMap)
    {
        products.push_back(e.first);
    }

    return products;
}
/** Logs a sale into sales_log */
void OrderBook::logSale(OrderBookEntry& entry)
{
    std::string sale = entry.timestamp 
    + "," + entry.product
    + "," + EntryType[entry.orderType] 
    + "," + std::to_string(entry.price) 
    + "," + std::to_string(entry.amount);

    std::cout << "Logging order into CSV >> " << sale << "\n \n";

    std::fstream csvFile;
    csvFile.open(salesLogCsvPath, std::ios::app);
    if(csvFile.is_open())
    {
        std::cout << "CSV "<< salesLogCsvPath << " FILE WAS SUCCESSFULLY OPENED" << "\n \n";
        csvFile << sale << '\n';

        csvFile.close();

        std::cout << "CSV FILE WAS SUCCESSFULY CLOSED" << "\n \n";

    }
}
/** return vector of Orders according to the sent filters*/
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, 
                                        std::string product, 
                                        const std::string& timestamp_)
{
    std::vector<OrderBookEntry> orders_sub;
    for (OrderBookEntry& e : orders)
    {
        if (e.orderType == type && 
            e.product == product && 
            e.timestamp == timestamp_ )
            {
                
                orders_sub.push_back(e);
            }
    }
    return orders_sub;
}


double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders)
{
    double max = 0.00;
    for (OrderBookEntry& e : orders)
    {
        if (e.price > max)max = e.price;
    }
    return max;
}


double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
{
    double min = 0.0;
    for (OrderBookEntry& e : orders)
    {
        if (e.price < min)min = e.price;
    }
    return min;
}

/**Gets the earlies time stamp in the order book */
std::string OrderBook::getEarliestTime()
{
    return orders[0].timestamp;
}

/** Get the latest time stamp in the order book*/
std::string OrderBook::getLatestTime()
{
    return orders[orders.size() - 1].timestamp;
}

std::string OrderBook::getNextTime(std::string timestamp)
{
    std::string next_timestamp = "";
    for (OrderBookEntry& e : orders)
    {
        if (e.timestamp > timestamp) 
        {
            next_timestamp = e.timestamp;
            break;
        }
    }
    if (next_timestamp == "")
    {
        next_timestamp = orders[orders.size() - 1].timestamp;
        std::cout << "\n \n";
        std::cout << "This is the most current time >> " << next_timestamp << '\n';
    }
    return next_timestamp;
}

void OrderBook::logOrder(OrderBookEntry& entry)
{   
  
    std::string order = entry.timestamp 
    + "," + entry.product
    + "," + EntryType[entry.orderType] 
    + "," + std::to_string(entry.price) 
    + "," + std::to_string(entry.amount);

    std::cout << "Logging order into CSV >> " << order << "\n \n";
   
    
    std::fstream csvFile;
    csvFile.open(orderBookCSVPath, std::ios::app);
    if(csvFile.is_open())
    {
        std::cout << "CSV " << orderBookCSVPath << " FILE WAS SUCCESFULLY OPENED" << '\n';
        csvFile << order << '\n';

        csvFile.close();

    }
    
}

void OrderBook::insertOrder(OrderBookEntry& order)
{
    orders.push_back(order);
    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
    std::cout << '\n';
    logOrder(order);
    
}

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp)
{
// asks = orderbook.asks
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, 
                                                 product, 
                                                 timestamp);
// bids = orderbook.bids
    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, 
                                                 product, 
                                                    timestamp);

    // sales = []
    std::vector<OrderBookEntry> sales; 

    // I put in a little check to ensure we have bids and asks
    // to process.
    if (asks.size() == 0 || bids.size() == 0)
    {
        std::cout << "\n";
        std::cout << "OrderBook::matchAsksToBids no bids or asks for > " << product << "\n";
        return sales;
    }

    // sort asks lowest first
    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);
    // sort bids highest first
    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);

    std::cout << "\n";
    std::cout << ">> " << product << '\n';

    // for ask in asks:
    std::cout << "max ask " << asks[asks.size()-1].price << '\n';
    std::cout << "min ask " << asks[0].price << '\n';
    std::cout << "max bid " << bids[0].price << '\n';
    std::cout << "min bid " << bids[bids.size()-1].price << '\n';
    std::cout << std::endl;
    
    for (OrderBookEntry& ask : asks)
    {
    //     for bid in bids:
        for (OrderBookEntry& bid : bids)
        {
    //         if bid.price >= ask.price # we have a match
            if (bid.price >= ask.price)
            {
    //             sale = new order()
    //             sale.price = ask.price
            OrderBookEntry sale{ask.price, 0, timestamp, 
                product, 
                OrderBookType::asksale};

                if (bid.username == "simuser")
                {
                    sale.username = "simuser";
                    sale.orderType = OrderBookType::bidsale;
                }
                if (ask.username == "simuser")
                {
                    sale.username = "simuser";
                    sale.orderType =  OrderBookType::asksale;
                }
            
    //             # now work out how much was sold and 
    //             # create new bids and asks covering 
    //             # anything that was not sold
    //             if bid.amount == ask.amount: # bid completely clears ask
                if (bid.amount == ask.amount)
                {
    //                 sale.amount = ask.amount
                    sale.amount = ask.amount;
    //                 sales.append(sale)
                    
                    sales.push_back(sale);
                   
    //                 bid.amount = 0 # make sure the bid is not processed again
                    bid.amount = 0;
    //                 # can do no more with this ask
    //                 # go onto the next ask
    //                 break
                    break;
                }
    //           if bid.amount > ask.amount:  # ask is completely gone slice the bid
                if (bid.amount > ask.amount)
                {
    //                 sale.amount = ask.amount
                    sale.amount = ask.amount;
    //                 sales.append(sale)
                    sales.push_back(sale);
                 
    //                 # we adjust the bid in place
    //                 # so it can be used to process the next ask
    //                 bid.amount = bid.amount - ask.amount
                    bid.amount =  bid.amount - ask.amount;
    //                 # ask is completely gone, so go to next ask                
    //                 break
                    break;
                }


    //             if bid.amount < ask.amount # bid is completely gone, slice the ask
                if (bid.amount < ask.amount && 
                   bid.amount > 0)
                {
    //                 sale.amount = bid.amount
                    sale.amount = bid.amount;
    //                 sales.append(sale)
                    sales.push_back(sale);
    //                 # update the ask
    //                 # and allow further bids to process the remaining amount
    //                 ask.amount = ask.amount - bid.amount
                    ask.amount = ask.amount - bid.amount;
    //                 bid.amount = 0 # make sure the bid is not processed again
                    bid.amount = 0;
    //                 # some ask remains so go to the next bid
    //                 continue
                    continue;
                }
            }
        }
    }
    return sales;             
}
