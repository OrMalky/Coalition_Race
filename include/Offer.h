#pragma once

class Offer
{
    public:
        Offer(int coalitionId, int agentId);
        int getCoalitionId() const;
        int getAgentId() const;
    
    private:
        int mCoalitionId;
        int mAgentId;
};