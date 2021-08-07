#include <iostream>
#include <thread>
#include "../include/Wallet.h"
#include "../include/MerkelMain.h"
#include "../include/TradingBot.h"
#include "../include/SettlementBot.h"
#include "../include/common.h"

bool bot1_connected = false;
bool settlementBot_connected = false;
int main()
{   
    //Initialize the application
    MerkelMain app{};
    app.Init();

    //Initialize Trading Bot
    TradingBot Bot{app};      
    Bot.Init();        

    if(bot1_connected)                      //Initialize Settlement Bot
    {
        std::cout << '\n' << '\n';
        std::cout << "Trading Bot successfully initialized!!" << "\n \n";

        
        SettlementBot Settler{app};
        Settler.Init();

        //sleep for a bit
        //std::this_thread::sleep_for(std::chrono::seconds(3));

        if(settlementBot_connected)         //Check Settlement Bot
        {
            std::cout << "\n \n";
            std::cout << "Settlement Bot successfully initialized!!" << "\n";
            std::cout << "Please choose values from the menu below!!" << "\n";
            std::cout << "HAPPY TRADING :)" << "\n \n" << std::endl;

            //std::this_thread::sleep_for(std::chrono::seconds(3));

            while(true)
            {
                app.runCycle();
                Bot.RunBotCycle();

                auto predictionsMap = Bot.predictions;

                Settler.RunBotCycle(predictionsMap);
            }

        }else{
            std::cout << '\n' << '\n';
            std::cout << "Settlement Bot failed to initialize... Exiting application" << "\n \n";
        }
        

    }else{
        std::cout << '\n' << '\n';
        std::cout << "Trading Bot failed to initialize... Exiting application" << "\n \n";
    }


    
    return 0;
}
