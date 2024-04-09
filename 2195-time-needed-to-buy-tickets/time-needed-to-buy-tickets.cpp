class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;
        int pos = 0;
        int i = 0;
        while (tickets[k] != 0) {
            pos  = i % tickets.size();
            i++;
            if(tickets[pos] == 0){
                continue;
            }
            tickets[pos] = tickets[pos] - 1 ;
            count++;
        }
        return count;
    }
};