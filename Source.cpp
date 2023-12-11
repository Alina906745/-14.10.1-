#include "Source.h"
#include "Trie.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
	TrieNode* root = getNewNode();
	insert(root, "mother");
	insert(root, "mom");
	insert(root, "milk");
	insert(root, "home");
	insert(root, "honey");
	insert(root, "clear");
	insert(root, "can");
	insert(root, "canoe");
	insert(root, "apple");
	insert(root, "orange");
	insert(root, "juce");
	insert(root, "jungle");

	string start;
	while (start != "#") {
		std::cout << "Enter word (or enter '#' for exit)" << std::endl;
		std::cin >> start;

		if (start != "#") {
			vector <string> words = allWordsByPrefix(root, start);
			for (auto& word : words)
			{
				std::cout << word << " ";
			}
			std::cout << std::endl;
		}
	}
	return 0;
}