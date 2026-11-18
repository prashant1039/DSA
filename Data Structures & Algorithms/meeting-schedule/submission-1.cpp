
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        if(intervals.size() <= 1)
        {
            return true;
        }

        sort(intervals.begin(), intervals.end(),
        [](Interval a, Interval b) {
            return a.start < b.start;
        });

        Interval currinterval = intervals[0];

        for(int i = 1; i < intervals.size(); i++)
        {
            if(currinterval.end > intervals[i].start)
            {
                return false;
            }
            else
            {
                currinterval = intervals[i];
            }
        }

        return true;
    }
};
