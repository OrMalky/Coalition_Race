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
        void addPartyOffer(Party* party);
        const vector<Party*> getParties() const;
        int getId() const;
    
    private:
        int mId;
        int mTotalMandates;
        vector<Party*> mOfferedParties;
        vector<Party*> mParties;
};