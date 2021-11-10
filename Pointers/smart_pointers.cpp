/* Notes: Can also use auto to infere the pointer type
 *  auto entity = make_unique<Entity>(); */
 
#include <iostream>
#include <memory>

using namespace std;

class Entity
{
public:
	Entity()
	{
		cout << "Created" << endl;
	}
	~Entity()
	{
		cout << "Destroyed" << endl;
	}
	void Print(){}  // To put a breakpoint
};

int main()
{	
	/* --- Unique pointer --- */ 
	{
		unique_ptr<Entity> entity = make_unique<Entity>();

		if (entity) 
		{
			// returns true as it is associated.
			cout << "Pointer in use" << endl;
		}
		entity->Print();
	}
	cin.get();

	/* --- Shared pointer --- */ 
	{
		shared_ptr<Entity> e0;
		{
			shared_ptr<Entity> e1 = make_shared<Entity>();
			cout << "Shared pointers to Entity (e1 pointing to it): " << e1.use_count() << endl;
			e0 = e1;
			cout << "Shared pointers to Entity (after e0 = e1): " << e0.use_count() << endl;
		}
		cout << "Shared pointers to Entity (e1 out of scope:) " << e0.use_count() << endl;
	} // Here memory is emptied
	cin.get();
	
	/* --- Weak pointer --- */ 
	{
		weak_ptr<Entity> e0;
		{
			shared_ptr<Entity> e1 = make_shared<Entity>();
			cout << "Shared pointers to Entity (e1 pointing to it): " << e1.use_count() << endl;
			e0 = e1;  // Can be shared	
			cout << "Shared pointers to Entity (after assigning a weak_ptr): " << e0.use_count() << endl;
		}  // Here memory is emptied
	} 
	cin.get();
	
	return 0;
}

