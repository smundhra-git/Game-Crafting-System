// test cases:
// An item is a component in multiple paths
// An item that we have is a component in multiple paths
//   (and we only use the component once)
// An item is craftable and used as a component
//  ..and we have some of it
// We have more than enough of everything we will need
// a binary tree with 50 nodes (5.5 levels), each leaf the same components,
// each requirement 100 items.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct item{
  string name;
  long long quantity;
  
};

long long Find(const vector<item>& v, const string& key){
  for(long long i = 0; i < v.size(); i++)
    if(v[i].name == key)
      return i;
  return -1;
}

void Swap(item& v1, item& v2){
  item temp = v1;
  v1 = v2;
  v2 = temp;
}

void Sort(vector<item>& v){
  for(long long i = 0; i < v.size(); i++)
    for(long long j = 0; j < v.size()-1; j++)
      if(v[j].name > v[j+1].name)
	Swap(v[j], v[j+1]);

  // collate results
  if(v.size() > 0){
    vector<item> combined;
    combined.push_back(v[0]);
    for(long long i = 1; i < v.size(); i++){
      long long last_combined = combined.size()-1;
      if(v[i].name == combined[last_combined].name)
	combined[last_combined].quantity += v[i].quantity;
      else
	combined.push_back(v[i]);
    }
    v.resize(combined.size());
    for(long long i = 0; i < combined.size(); i++)
      v[i] = combined[i];
  }
}
       
void Make_Components(const vector<vector<item> >& recipes,
		     vector<item>& inventory,
		     vector<item>& components, string desired, long long demand){
  // cout << "Making " << demand << " " << desired << endl;
  long long pos = Find(inventory, desired);
  for(long long i = 0; i < recipes[pos].size(); i++){
    item cur_component = recipes[pos][i];
    // do I have to make this?
    long long component_pos = Find(inventory, cur_component.name);
    long long amount_we_have = inventory[component_pos].quantity;
    long long amount_we_need = cur_component.quantity * demand;
    if(amount_we_have >= amount_we_need){
      inventory[component_pos].quantity -= amount_we_need;
    }
    else{
      long long amount_leftover = amount_we_need - amount_we_have;
      inventory[component_pos].quantity = 0;
      if(recipes[component_pos].size() == 0){ // get it from the wild
	item desired_component;
	desired_component.name = inventory[component_pos].name;
	desired_component.quantity = amount_leftover;
	components.push_back(desired_component);
      }
      else
	Make_Components(recipes, inventory, components, cur_component.name, amount_leftover);
    }
  }
}
int main(){
  long long cur_case = 1;
  long long n;
  cin >> n;
  while(n > 0){
    vector<item> inventory(n);
    for(long long i = 0; i < n; i++){
      cin >> inventory[i].name;
      cin >> inventory[i].quantity;
    }
    vector<vector<item> > recipes(n);
    for(long long i = 0; i < n; i++){
      long long c;
      cin >>c;
      recipes[i].resize(c);
      for(long long j = 0; j <c;j++){
	cin >> recipes[i][j].quantity;
	cin >> recipes[i][j].name;
      }
    }
    string desired;
    cin >> desired;
    vector<item> components;
    Make_Components(recipes, inventory, components, desired, 1);
    Sort(components);
    cout << "Case " << cur_case<<": " << endl;
    for(long long i = 0; i < components.size(); i++){
      cout << components[i].name << " " << components[i].quantity << endl;
    }
    cur_case++;
    cin >> n;
  }
  return 0;
}
	
