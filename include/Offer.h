#pragma once

class Offer
{
    public:
        Offer(int coalitionId);
        int getCoalitionId() const;
    
    private:
        int mCoalitionId;
};