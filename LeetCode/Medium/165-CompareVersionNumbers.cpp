class Solution {
public:
    int compareVersion(string version1, string version2) {
        unsigned int val1 = 0, val2 = 0, ptr1=0, ptr2=0;
        while (ptr1 < version1.size() || ptr2 < version2.size()) {
            val1 = 0, val2 = 0;
            while (ptr1 < version1.size() && version1[ptr1] != '.') {
                val1 += version1[ptr1]-'0';
                val1 *= 10;
                ptr1++;
            }
            while (ptr2 < version2.size() && version2[ptr2] != '.') {
                val2 += version2[ptr2]-'0';
                val2 *= 10;
                ptr2++;
            }
            if (val1 < val2) {
                return -1;
            } else if (val1 > val2) {
                return 1;
            }

            while (ptr1 < version1.size() && version1[ptr1] == '.') ptr1++;
            while (ptr2 < version2.size() && version2[ptr2] == '.') ptr2++;
        }
        if (ptr1 == version1.size() && ptr2 == version2.size()) {
            return 0;
        }

        if (ptr1==version1.size()) {
            return -1;
        } else {
            return 1;
        }
    }
};