    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        dic = {}
        maxlen = 0
        pre = -1
        for i in range(len(s)):
            if s[i] in dic:
                pre = max(pre, dic[s[i]])
            maxlen = max(maxlen, i-pre)
            dic[s[i]] = i
        return maxlen


