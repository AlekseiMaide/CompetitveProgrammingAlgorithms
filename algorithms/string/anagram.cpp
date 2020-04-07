bool isAnagram(std::string s, std::string t) {
    int sLen = s.length();
    int tLen = t.length();

    if (sLen != tLen) return false;

    int counts[26] = {0};
    for (int i = 0; i < sLen; i++) {
        counts[s[i] - 'a']++;
    }

    for (int i = 0; i < tLen; i++) {
        counts[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (counts[i] != 0) return false;
    }


    return true;
}

/**
 * Group Anagrams by turning string to their canonical form (Lexiographical) by sorting.
 *
 * Canonical from is form is often used in grouping problems for example:
 *   Irreducible numbers 15/20 and 12/16 both reduce to 3/4
 *   Irreducible functions 4x + 6 = 8y -> 2x + 3 = 4y
 *
 */
vector<vector<string>> groupAnagrams(vector<string>& words) {
    vector<vector<string> > result;

    map<string, int> groups;

    for (string word : words) {
        string originalWord = word;

        sort(word.begin(), word.end());

        auto itr = groups.find(word);
        if (itr == groups.end()) {
            result.push_back(vector<string>());
            groups.insert(make_pair(word , result.size() - 1));
        }

        vector<string>& group = result.at(groups[word]);
        group.push_back(originalWord);
    }

    return result;
}
