#include <iostream>

unsigned int * inputTimeEating(unsigned int size);
unsigned int amountCookies(unsigned int * eatingOneCakeTime, unsigned int size);
unsigned int cookiesToBoxes(unsigned int cookies, unsigned long long cakesInBox);
 
int main()
{
    unsigned long long tests{};
    std::cin >> tests;

    while(tests--)
    {
        unsigned int people{};           //number of players
        unsigned long long cakesInBox{}; // number of cookies in one box

        std::cin >> people >> cakesInBox;

        unsigned int * eatingOneCakeTime = inputTimeEating(people);

        unsigned int cookies = amountCookies(eatingOneCakeTime, people);

        std::cout << cookiesToBoxes(cookies, cakesInBox) << std::endl;

        delete [] eatingOneCakeTime;
    }

    return 0;
}

unsigned int * inputTimeEating(unsigned int size)
{
    unsigned int * eatingOneCakeTime = new unsigned int[size];  // time to eat one cookie for 
                                                                // all subsequent players [s
    for(unsigned int i = 0; i < size; i++)
    {
        std::cin >> eatingOneCakeTime[i];
    }

    return eatingOneCakeTime;
}

unsigned int amountCookies(unsigned int * eatingOneCakeTime, unsigned int size)
{
    unsigned int cookies{};
    constexpr unsigned int secondsInOneDay = 86400;

    for(unsigned int i = 0; i < size; i++)
    {
        cookies += secondsInOneDay / eatingOneCakeTime[i];
    }
    
    return cookies;
}

unsigned int cookiesToBoxes(unsigned int cookies, unsigned long long cakesInBox)
{
    auto temp = cookies / cakesInBox;
    return (cookies % cakesInBox) ? (temp + 1) : temp;
}



