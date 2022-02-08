#include<algorithm>
#include<numeric>
#include<iostream>
#include<iterator>
#include<vector>


//https://pl.spoj.com/problems/GLUTTON/

unsigned int cookiesToBoxes(unsigned int cookies, unsigned long long cakesInBox);

int main()
{
    long long tests{};

    std::cin >> tests;

    while(tests--)
    {
        unsigned int people{};  //number of players
        unsigned long long cakesInBox{}; // number of cookies in one box
        std::cin >> people >> cakesInBox;

        std::vector<unsigned int> eatingOneCakeTime;  // time to eat one cookie for 
                                                      // all subsequent players [s]
        std::generate_n(std::back_inserter(eatingOneCakeTime), 
                        people, 
                        [](){ 
                            return *(std::istream_iterator<unsigned int>(std::cin));
                        }
        );

        constexpr unsigned int secondsInOneDay = {24 * 3600};

        auto sumCookies = std::accumulate(eatingOneCakeTime.begin(),
                                eatingOneCakeTime.end(), 
                                0, 
                                [](auto a, auto time)
                                {
                                    return std::move(a) + secondsInOneDay / time;
                                }
        );

        std::cout << cookiesToBoxes(sumCookies, cakesInBox) << '\n';
    }

    return 0;
}

unsigned int cookiesToBoxes(unsigned int cookies, unsigned long long cakesInBox)
{
    auto temp = cookies / cakesInBox;
    return (cookies % cakesInBox) ? (temp + 1) : temp;
}