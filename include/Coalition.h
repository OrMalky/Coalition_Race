#pragma once

#include <vector>
#include "Party.h"

class Party;

using std::vector;

class Coalition
{
    public:
        Coalition(int id);
        int getTotalMandates() const;
        void addParty(Party* party);
        bool checkOfferedParties(int partyId);
        void addPartyOffer(int partyId);
        const vector<Party*> getParties() const;
        int getId() const;
    
    private:
        int mId;
        int mTotalMandates;
        vector<int> mOfferedParties;
        vector<Party*> mParties;
};