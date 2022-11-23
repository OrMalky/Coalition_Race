#pragma once

#include <vector>
#include "Party.h"

class Party;

using std::vector;

class Coalition
{
    public:
        Coalition(int id);  //Constructor
        Coalition(const Coalition& c);  //Copy Constructor
        ~Coalition() = default; //Destructor [We actually want the default destructor! we dont want to remove the parties inside mParties vector]
        Coalition& operator=(const Coalition& other);   //Assignment Operator

        /*  Rule of 5 [not actually needed]
        Coalition(Coalition&& c);   //Move Constructor
        Coalition& operator=(Coalition&& other);    //Move Assignment Operator
        */

        int getTotalMandates() const;
        void addParty(Party* party);
        bool checkOfferedParties(int partyId);
        void addPartyOffer(int partyId);
        const vector<Party*> getParties() const;
        const vector<int> getOfferedParties() const;
        int getId() const;
    
    private:
        int mId;
        int mTotalMandates;
        vector<int> mOfferedParties;
        vector<Party*> mParties;
};