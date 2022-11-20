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
        void addParty(Party& party);
        bool checkOfferedParties(int partyId);
        void addPartyOffer(Party& party);
        vector<Party&> getParties();
        int getId() const;
    
    private:
        int mId;
        int mTotalMandates;
        vector<Party&> mOfferedParties;
        vector<Party&> mParties;
};