0. ��͸� ���� ���
 
void pick(int n, vector<int>& picked, int toPick){
    if(toPick==0) {
        printPicked(picked);
        return;
    }
 
    int smallest=picked.empty() ? 0 : picked.back()+1;
    for(int next=smallest; next<n; ++next){
        picked.push_back(next);
        pick(n,picked, toPick-1);
        picked.pop_back();
    }
}
 
1.STL Ȱ���� ���(�ϳ��ϳ� ����Ҷ� ���ϴ�)
 
bool next_k_permutation(vector<int>&v, int k){
    sort(v.begin()+k, v.end(), greater<int>());
    return next_permutation(v.begin(), v.end());
}
 
bool next_k_combination(vector<int>&v, int k){
    while(next_k_permutation(v,k)){
        if(is_sorted(v.begin(), v.begin()+k))
            return true;
    }
    return false;
}
 
//is_sorted �Լ��� c++11�������� ����
bool is_sorted(vector<int>::iterator first, vector<int>::iterator last){
    if(first==last) return true;
    vector<int>::iterator next=first;
 
    while(++next != last){
        if(*next<*first)
            return false;
        ++first;
    }
    return true;
}