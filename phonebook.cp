#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Contact
{
  string name;
  string phoneNumber;
  string email;
};

vector < Contact > phoneBook;

void addContact ()
{
  Contact newContact;
  cout << "Enter the name of the new contact: ";
  getline (cin, newContact.name);
  cout << "Enter the phone number of the new contact: ";
  getline (cin, newContact.phoneNumber);
  cout << "Enter the email address of the new contact: ";
  getline (cin, newContact.email);
  phoneBook.push_back (newContact);
  cout << "Contact added successfully!" << endl;
}

void deleteContact ()
{
  string searchQuery;
  int numContactsFound = 0;
  cout <<"Enter the name, phone number, or email address of the contact you wish to   delete: ";
  getline (cin, searchQuery);
  for (int i = 0; i < phoneBook.size (); i++)
    {
      if (phoneBook[i].name == searchQuery
	
              || phoneBook[i].phoneNumber == searchQuery
              || phoneBook[i].email == searchQuery)
	{
	  phoneBook.erase (phoneBook.begin () + i);
	  numContactsFound++;
	  i--;	// since the element at i was removed, the next element now occupies the ith position
	}
    }
  if (numContactsFound == 0)
    {
      cout << "No contacts found matching the search query." << endl;
    }
  else
    {
      cout << numContactsFound <<" contact(s) matching the search query deleted successfully!" << endl;
    }
}

void searchContacts ()
{
  string searchQuery;
  int numContactsFound = 0;
  cout << "Enter the name, phone number, or email address of the contact you wish to search for: ";
  getline (cin, searchQuery);
  for (int i = 0; i < phoneBook.size (); i++)
    {
      if (phoneBook[i].name == searchQuery
	  || phoneBook[i].phoneNumber == searchQuery
	  || phoneBook[i].email == searchQuery)
	{
	  cout << "Name: " << phoneBook[i].name << endl;
	  cout << "Phone number: " << phoneBook[i].phoneNumber << endl;
	  cout << "Email: " << phoneBook[i].email << endl;
	  numContactsFound++;
	}
    }
  if (numContactsFound == 0)
    {
      cout << "No contacts found matching the search query." << endl;
    }
 
 else
    {
      cout << numContactsFound <<" contact(s) found matching the search query." << endl;
    }
}

void viewAllContacts ()
{
  if (phoneBook.size () == 0)
    {
       cout << "No contacts found in the phone book." << endl;
    }
  else
    {
      cout << "All contacts in the phone book:" << endl;
      for (int i = 0; i < phoneBook.size (); i++)
	{
	  cout << "Name: " << phoneBook[i].name << endl;
	  cout << "Phone number: " << phoneBook[i].phoneNumber << endl;
	  cout << "Email: " << phoneBook[i].email << endl;
	  cout << endl;
	}
    }
}

void updateContact ()
{
  string searchQuery;
  int numContactsFound = 0;
  cout <<"Enter the name, phone number, or email address of the contact you wish to update: ";
  getline (cin, searchQuery);
  for (int i = 0; i < phoneBook.size (); i++)
    {
      if (phoneBook[i].name == searchQuery
	  || phoneBook[i].phoneNumber == searchQuery
	  || phoneBook[i].email == searchQuery)
	{
	  cout << "Current information for the selected contact:" << endl;
	  cout << "Name: " << phoneBook[i].name << endl;
	  cout << "Phone number: " << phoneBook[i].phoneNumber << endl;
	  cout << "Email: " << phoneBook[i].email << endl;
	  cout << endl;
	  
              cout << "Enter the updated information for the contact:" << endl;
	  cout << "Name (leave blank to keep current name): ";

	  string updatedName;
	  getline (cin, updatedName);
	  if (updatedName != "")
	    {
	      phoneBook[i].name = updatedName;
	    }
	  cout << "Phone number (leave blank to keep current phone number): ";
	  string updatedPhoneNumber;
	  getline (cin, updatedPhoneNumber);
	  if (updatedPhoneNumber != "")
	    {
                   phoneBook[i].phoneNumber = updatedPhoneNumber;
	    }
	  cout << "Email (leave blank to keep current email): ";
	  string updatedEmail;
	  getline (cin, updatedEmail);
	  if (updatedEmail != "")
	    {
	      phoneBook[i].email = updatedEmail;
	    }
	  cout << "Contact updated successfully!" << endl;
	  numContactsFound++;
	}
    }
  if (numContactsFound == 0)
    {
      cout << "No contacts found matching the search query." << endl;
    }
}

void sortContacts ()
{
  int sortOption;
  cout << "Enter 1 to sort by name, 2 to sort by phone number, or 3 to sort by email address: ";
  cin >> sortOption;
  cin.ignore ();	   // ignore the newline character left in the input stream by cin
  if (sortOption == 1)
    {
    

      sort (phoneBook.begin (), phoneBook.end (), [](const Contact & a, const Contact & b)
     {
         return a.name < b.name;}
      );
      cout << "Phone book sorted by name!" << endl;
    }
  else if (sortOption == 2)
    {
      sort (phoneBook.begin (), phoneBook.end (),
	    [](const Contact & a, const Contact & b)
	    {
	    return a.phoneNumber < b.phoneNumber;}
      );
      cout << "Phone book sorted by phone number!" << endl;
    }
  else if (sortOption == 3)
    {
      sort (phoneBook.begin (), phoneBook.end (),
	    [](const Contact & a, const Contact & b)
	    {
	    return a.email < b.email;}
      );
      cout << "Phone book sorted by email address!" << endl;
    }
  else
    {
      cout << "Invalid input. Phone book not sorted." << endl;
    }
}

void groupContacts ()
{
// This function could be implemented to group contacts by category or tag using a map or another data structure,
// but for simplicity's sake, we will just group contacts by first letter of their name.
  vector < vector < Contact >> groupedContacts (26);
  for (int i = 0; i < phoneBook.size (); i++)
    {
      char firstLetter = phoneBook[i].name[0];
      if (isupper (firstLetter))
	{
	  firstLetter = tolower (firstLetter);	// convert to lowercase for ease of indexing the vector
	
      }
      groupedContacts[firstLetter - 'a'].push_back (phoneBook[i]);
    }
  cout << "Contacts grouped by first letter of name:" << endl;
  for (int i = 0; i < groupedContacts.size (); i++)
    {
      if (groupedContacts[i].size () > 0)
	{
	  cout << (char) ('a' + i) << endl;	// convert back to uppercase for display
	  for (int j = 0; j < groupedContacts[i].size (); j++)
	    {
	      cout << "  " << groupedContacts[i][j].name << endl;
	    }
	}
    }
}

int main ()
{
  int userChoice;
  do
    {
      cout << "Select an option:" << endl;
      cout << "1. Add new contact" << endl;
      cout << "2. Delete contact" << endl;
      cout << "3. Search for contact" << endl;
      cout << "4. View all contacts" << endl;
      cout << "5. Update contact" << endl;
      cout << "6. Sort contacts" << endl;
      cout << "7. Group contacts" << endl;
      cout << "8. Exit" << endl;
      cout << "Enter your choice: ";
      cin >> userChoice;
      cin.ignore ();		// ignore the newline character left in the input stream by cin
      switch (userChoice)
	{
	case 1:
	  addContact ();
	  break;
	case 2:
	  deleteContact ();
	  break;
	


            case 3:
	  searchContacts ();
	  break;
	case 4:
	  viewAllContacts ();
	  break;
	case 5:
	  updateContact ();
              break;
	case 6:
	  sortContacts ();
	  break;
	case 7:
	  groupContacts ();
	  break;
	case 8:
	  cout << "Goodbye!" << endl;
	  break;
	default:
	  cout << "Invalid choice. Please enter a number from 1 to 8." <<
	    endl;
	  break;
	}
      cout << endl;
    }
  while (userChoice != 8);
  return 0;
}

