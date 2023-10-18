#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }
    map<string, TwitterData> UsernameMap, EmailMap;
    for (int i = 0; i < 5; i++){
        UsernameMap.insert({(twitter_data+i)->getUserName(), *(twitter_data+i)});
        EmailMap.insert({(twitter_data+i)->getEmail(), *(twitter_data+i)});
    }
    for (std::map<string,TwitterData>::iterator UsernameMapIt = UsernameMap.begin(); UsernameMapIt != UsernameMap.end(); UsernameMapIt++){
        cout << "Key:  " << UsernameMapIt->first << ",  Value:  " << UsernameMapIt->second.print() << "\n";
    } 
    cout << "Search for key:  "<< UsernameMap.find("savage1")->first << "  Value:  " << UsernameMap.find("savage1")->second.print() << "\n";
    UsernameMap.erase("savage1");
    for (std::map<string,TwitterData>::iterator EmailMapIt = EmailMap.begin(); EmailMapIt != EmailMap.end(); EmailMapIt++){
        cout << "Key:  " << EmailMapIt->first << ",  Value:  " << EmailMapIt->second.print() << "\n";
    } 
    cout << "Search for key:  "<< EmailMap.find("kat@gmail.com")->first << "  Value:  " << EmailMap.find("kat@gmail.com")->second.print() << "\n";
    EmailMap.erase("kat@gmail.com");

    

    return 0;
}