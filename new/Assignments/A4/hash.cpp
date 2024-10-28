// // Java program to implement Rehashing

// import java.util.ArrayList;

// class Map<K, V> {

// 	class MapNode<K, V> {

// 		K key;
// 		V value;
// 		MapNode<K, V> next;

// 		public MapNode(K key, V value)
// 		{
// 			this.key = key;
// 			this.value = value;
// 			next = null;
// 		}
// 	}

// 	// The bucket array where
// 	// the nodes containing K-V pairs are stored
// 	ArrayList<MapNode<K, V> > buckets;

// 	// No. of pairs stored - n
// 	int size;

// 	// Size of the bucketArray - b
// 	int numBuckets;

// 	// Default loadFactor
// 	final double DEFAULT_LOAD_FACTOR = 0.75;

// 	public Map()
// 	{
// 		numBuckets = 5;

// 		buckets = new ArrayList<>(numBuckets);

// 		for (int i = 0; i < numBuckets; i++) {
// 			// Initialising to null
// 			buckets.add(null);
// 		}
// 		System.out.println("HashMap created");
// 		System.out.println("Number of pairs in the Map: " + size);
// 		System.out.println("Size of Map: " + numBuckets);
// 		System.out.println("Default Load Factor : " + DEFAULT_LOAD_FACTOR + "\n");
// 	}

// 	private int getBucketInd(K key)
// 	{

// 		// Using the inbuilt function from the object class
// 		int hashCode = key.hashCode();

// 		// array index = hashCode%numBuckets
// 		return (hashCode % numBuckets);
// 	}

// 	public void insert(K key, V value)
// 	{
// 		// Getting the index at which it needs to be inserted
// 		int bucketInd = getBucketInd(key);

// 		// The first node at that index
// 		MapNode<K, V> head = buckets.get(bucketInd);

// 		// First, loop through all the nodes present at that index
// 		// to check if the key already exists
// 		while (head != null) {

// 			// If already present the value is updated
// 			if (head.key.equals(key)) {
// 				head.value = value;
// 				return;
// 			}
// 			head = head.next;
// 		}

// 		// new node with the K and V
// 		MapNode<K, V> newElementNode = new MapNode<K, V>(key, value);

// 		// The head node at the index
// 		head = buckets.get(bucketInd);

// 		// the new node is inserted
// 		// by making it the head
// 		// and it's next is the previous head
// 		newElementNode.next = head;

// 		buckets.set(bucketInd, newElementNode);

// 		System.out.println("Pair(" + key + ", " + value + ") inserted successfully.\n");

// 		// Incrementing size
// 		// as new K-V pair is added to the map
// 		size++;

// 		// Load factor calculated
// 		double loadFactor = (1.0 * size) / numBuckets;

// 		System.out.println("Current Load factor = " + loadFactor);

// 		// If the load factor is > 0.75, rehashing is done
// 		if (loadFactor > DEFAULT_LOAD_FACTOR) {
// 			System.out.println(loadFactor + " is greater than " + DEFAULT_LOAD_FACTOR);
// 			System.out.println("Therefore Rehashing will be done.\n");

// 			// Rehash
// 			rehash();

// 			System.out.println("New Size of Map: " + numBuckets + "\n");
// 		}

// 		System.out.println("Number of pairs in the Map: " + size);
// 		System.out.println("Size of Map: " + numBuckets + "\n");
// 	}

// 	private void rehash()
// 	{

// 		System.out.println("\n***Rehashing Started***\n");

// 		// The present bucket list is made temp
// 		ArrayList<MapNode<K, V> > temp = buckets;

// 		// New bucketList of double the old size is created
// 		buckets = new ArrayList<MapNode<K, V> >(2 * numBuckets);

// 		for (int i = 0; i < 2 * numBuckets; i++) {
// 			// Initialised to null
// 			buckets.add(null);
// 		}
// 		// Now size is made zero
// 		// and we loop through all the nodes in the original bucket list(temp)
// 		// and insert it into the new list
// 		size = 0;
// 		numBuckets *= 2;

// 		for (int i = 0; i < temp.size(); i++) {

// 			// head of the chain at that index
// 			MapNode<K, V> head = temp.get(i);

// 			while (head != null) {
// 				K key = head.key;
// 				V val = head.value;

// 				// calling the insert function for each node in temp
// 				// as the new list is now the bucketArray
// 				insert(key, val);
// 				head = head.next;
// 			}
// 		}

// 		System.out.println("\n***Rehashing Ended***\n");
// 	}

// 	public void printMap()
// 	{

// 		// The present bucket list is made temp
// 		ArrayList<MapNode<K, V> > temp = buckets;

// 		System.out.println("Current HashMap:");
// 		// loop through all the nodes and print them
// 		for (int i = 0; i < temp.size(); i++) {

// 			// head of the chain at that index
// 			MapNode<K, V> head = temp.get(i);

// 			while (head != null) {
// 				System.out.println("key = " + head.key + ", val = " + head.value);

// 				head = head.next;
// 			}
// 		}
// 		System.out.println();
// 	}

// 	//Function to get an element from Map
// 	public V getValue(K key){
// 		//Get actual index of the key
// 		int actualIndex = getBucketInd(key);
// 		MapNode<K,V> temp = buckets.get(actualIndex);
// 		//Search for key in list
// 		while(temp != null){
// 			if(temp.key == key){
// 				return temp.value;
// 			}
// 			temp = temp.next;
// 		}
// 		return null;
// 	}
// }

// public class GFG {

// 	public static void main(String[] args)
// 	{

// 		// Creating the Map
// 		Map<Integer, String> map = new Map<Integer, String>();

// 		// Inserting elements
// 		map.insert(1, "Geeks");
// 		map.printMap();

// 		map.insert(2, "forGeeks");
// 		map.printMap();

// 		map.insert(3, "A");
// 		map.printMap();

// 		map.insert(4, "Computer");
// 		map.printMap();

// 		map.insert(5, "Portal");
// 		map.printMap();
	
// 	//Get element from Map
// 	int key = 4;
// 	String value = map.getValue(key);
// 	System.out.println("Value at key "+ key +" is: "+ value);
// 	}
// }









// Implementing hash table in C++
//Open Hashing (Separate Chaining)
#include <iostream>
#include <list>
using namespace std;
class HashTable
{
  int capacity;
  list<int> *table;
public:
  HashTable(int V);
  void insertItem(int key, int data);
  void deleteItem(int key);
  int checkPrime(int n)
  {
  int i;
  if (n == 1 || n == 0)
  {
    return 0;
  }
  for (i = 2; i < n / 2; i++)
  {
    if (n % i == 0)
    {
    return 0;
    }
  }
  return 1;
  }
  int getPrime(int n)
  {
	  if (n % 2 == 0)
	  {
	    n++;
	  }
	  while (!checkPrime(n))
	  {
	    n += 2;
	  }
  return n;
  }
  
  int hashFunction(int key)
  {
  	return (key % capacity);
  }
  
  void displayHash();
};
HashTable::HashTable(int c)
{
  int size = getPrime(c);
  this->capacity = size;
  table = new list<int>[capacity];
}

void HashTable::insertItem(int key, int data)
{
  int index = hashFunction(key);
  table[index].push_back(data);
}
void HashTable::deleteItem(int key)
{
  int index = hashFunction(key);
  list<int>::iterator i;
  for (i = table[index].begin(); i != table[index].end(); i++)
  {
  if (*i == key)
    break;
  }

  if (i != table[index].end())
  table[index].erase(i);
}
void HashTable::displayHash()
{
for (int i = 0; i < capacity; i++)
  {
  cout << "table[" << i << "]";
  for (auto x : table[i])
    cout << " --> " << x;
  cout << endl;
  }
}
int main()
{
  int key[] = {231, 321, 212, 321, 433, 262};
  int data[] = {123, 432, 523, 43, 423, 111};
  int size = sizeof(key) / sizeof(key[0]);

  //HashTable h(size);
  HashTable h(12);
  for (int i = 0; i < size; i++)
  		h.insertItem(key[i], data[i]);

  h.deleteItem(231);
  h.displayHash();
}
