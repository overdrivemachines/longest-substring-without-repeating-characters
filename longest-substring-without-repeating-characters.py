class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # print("string:", s)
        result = 0
        my_set = set()
        sub_start_index = 0
        for i in range(len(s)):
            if s[i] not in my_set:
                my_set.add(s[i])
                result = max(result, len(my_set))

                # print(i, ": adding", s[i], "to my_set: ", my_set)
            else:
                # print(i, ":", s[i], "exists in my_set: ", my_set)

                while s[sub_start_index] != s[i]:
                    # print("Removing", s[sub_start_index])
                    my_set.remove(s[sub_start_index])
                    sub_start_index += 1
                sub_start_index += 1
                # sub_length -= 1

        return max(result, len(my_set))


sol = Solution()
s = "abcabcbb"
# s = "bbbbb"
# s = "pwwkew"
# s = "dvdf"
print(sol.lengthOfLongestSubstring(s))
