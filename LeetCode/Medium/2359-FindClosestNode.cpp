class Solution
{
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        vector<int> dist1(edges.size(), -1);
        vector<int> dist2(edges.size(), -1);
        vector<bool> visited(edges.size(), false);
        int cur = node1, dist = 0;
        while (cur != -1 && !visited[cur])
        {
            dist1[cur] = dist;
            visited[cur] = true;
            dist++;
            cur = edges[cur];
        }
        fill(visited.begin(), visited.end(), false);
        cur = node2, dist = 0;
        while (cur != -1 && !visited[cur])
        {
            dist2[cur] = dist;
            visited[cur] = true;
            dist++;
            cur = edges[cur];
        }

        int best = 99999999, idx = -1;
        for (int i = 0; i < edges.size(); i++)
        {
            if (max(dist1[i], dist2[i]) < best && min(dist1[i], dist2[i]) != -1)
            {
                idx = i;
                best = max(dist1[i], dist2[i]);
            }
        }

        return idx;
    }
};