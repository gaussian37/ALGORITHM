/*
�ۼ���: gaussian37
������: https://gaussian37.github.io/math-algorithm-trie/
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �ڽ� ����� ������ �� �ܾ��� ������ �ش��մϴ�.
// ���� ���ڸ� ������ (0 ~9) ������� 10, ���ĺ� �ҹ��ڸ� ������ 26���� ���ϸ� �˴ϴ�.
const int char_size = 26;

// Trie vector�� element
struct Node {
	// ���� �ܾ �ش��ϴ� ������� ����
	bool valid;
	// char_size ��ŭ�� ũ�⸦ ������ �ڽ� ���
	vector<int> children;

	Node() {
		valid = false;
		children.assign(char_size, -1);
	}
};

// trie vector�� �ʱ�ȭ �մϴ�.
// root�� �����ϰ� root�� node ��ȣ�� 0�� �˴ϴ�.
int Init(vector<Node>& trie) {
	Node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}

// ���ڿ�s�� �ԷµǸ� trie�� �����մϴ�.
void Add(vector<Node>& trie, int node, string& s, int index) {
	// index�� trie������ depth�� �ش��մϴ�.
	// index(depth)�� ���ڿ��� ���̿� �������� �� ��忡 �Էµ� ���ڿ��� �Ҵ��մϴ�.
	if (index == s.size()) {
		trie[node].valid = true;
		return;
	}

	// ���� �ε����� �ش��ϴ� ���ڸ� ���ڷ� ��Ī��ŵ�ϴ�.
	int c = s[index] - 'a';
	// ���� ����� �ڽ� ��� �� c�� �ش��ϴ� ��尡 �������� �ʾҴٸ� �����մϴ�.
	if (trie[node].children[c] == -1) {
		// trie�� ���ο� ��带 ������ �ְ� �� ����� ��ȣ�� ���� �޽��ϴ�.
		int next = Init(trie);
		// ���� ���� ��� ��ȣ�� c�� �ڽ� ��忡 �Ҵ��� �ݴϴ�.
		trie[node].children[c] = next;
	}

	// ���� index�� ���ڿ� ��ü ���̸�ŭ Ž������ �ʾ����Ƿ� ���ڿ��� ���� �ε����� Ž���մϴ�.
	// ��, trie���� �� ���� depth ���� ���ڿ��� �����ϴ� �۾��� ��͸� ���Ͽ� �ݺ��մϴ�.
	Add(trie, trie[node].children[c], s, index + 1);
}

// trie���� Ư�� ���ڿ� s�� ã�� �۾��� �մϴ�.
// trie�� ������ �����Ͽ��� ������ O(���ڿ� s�� ����)���� ã�� �� �ֽ��ϴ�.
bool TrieSearch(vector<Node>& trie, int node, string& s, int index) {
	//���ڿ� �ε����� ���� ��ŭ trie�� Ž���� ���,
	if (index == s.size()) {		
		// ���� ����� valid�� ��ȿ�ϴٸ� �ܾ �����մϴ�.
		if (trie[node].valid) {		
			return true;
		}
		else {
			return false;
		}
	}

	bool ret = false;
	int c = s[index] - 'a';
	// c�� �ڽ� ��尡 �����Ǿ� �ִٸ� ��� Ʈ���� Ž���մϴ�.
	// ���� �������� �ʾҴٸ� trie�� ã�� ���ڿ��� �����ϴ�.
	if (trie[node].children[c] != -1) {
		ret = TrieSearch(trie, trie[node].children[c], s, index + 1);
	}

	return ret;
}

int main() {

	// Trie�� ���� ��ü �ܾ� ��
	vector<string> dic = { "a", "to", "tea", "ted", "i", "in", "inn" };

	// �׽�Ʈ �� �� �ܾ� ��
	vector<string> test = { "a", "to", "inn", "tee", "aee", "vae"};
	
	// Trie�� ������ vector
	vector<Node> trie;
	// Trie �ʱ�ȭ�� ���� root ����
	int root = Init(trie);
	// �ܾ���� Trie�� ����
	for(auto word : dic){
		Add(trie, root, word, 0);
	}
	
	// �׽�Ʈ �ܾ� ����
	for (auto word : test) {
		cout << word << ": ";
		if (TrieSearch(trie, root, word, 0)) {
			cout<<"Exist"<< endl;
		}
		else {
			cout<<"Not exist"<<endl;
		}
	}
}