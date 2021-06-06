# MyNovelList
Digital library created for a UWS module.

Change Log 06/06/2021 - Thomas
- WORK IN PROGRESS - NOT FULLY TESTED
- Refactored MNL_SignIn to replace panels with custom ones
	- This allows double buffering to be enabled which stops the 
	  flickering when showing/hiding panels

Change Log 05/06/2021 - Thomas
- Refactored sign-in to remove leading and trailing whitespace 
  from usernames. Passwords may still contain spaces wherever

Change Log 04/06/2021 - Thomas
- Refactored encryption and decryption into associated functions
- Refactored MNL_Home and MNL_SignIn to accomodate these changes
- Reworked the sign-in process to check for a correct username 
  using data from usernameVector before performing decryption
	- This change should save on memory by exiting the sign-in attempt 
	  before decrypting if the wrong username is used
- Refactored exit button on-click handler

Change Log 27/05/2021 - Thomas
- Fixed bug with deleting node from the end of the list

Change Log 14/05/2021 - Thomas
- Refactored Sort.h
- Used 4 lambdas to simplify sort comparisons
- Fixed bug with deleting nodes

Change Log 14/05/2021 - Thomas
- Refactored Sort to account for volume number when sorting by 
  author or series

Change Log 14/05/2021 - Thomas
- Added Clear button to allow users to clear text and score/volume values
- Refactored the editing process so that when a user selects a book from the 
  ListView, the data is automatically added to the relevant fields. If the user has
  added their own text then it will not be overwritten
- Refactored sort timing into a function which takes a function template
- Added timing to all of the sorting algorithms
- Fixed Release version crash caused by no sorting method being selected
	- Seems like the compiler removed the default break, and thus the code was 
	  trying to read a nullptr

Change Log 13/05/2021 - Thomas
- Refactored serialisation to encrypt usernames, passwords and user book data
- Added a cancel button to the registration panel
- Fixed bug which allowed multiple users to register with the same username
- Added timer to one instance of bubble sorting (by title, ascending)
	- Will be added across the board after refactoring using lambda functions
 
Change Log 13/05/2021 - Thomas
- Added shell sort
- Refactored every .h and .cpp file to add comments (lecturer requirement) 
 
Change Log 12/05/2021 - Thomas
- Added insertion sort
- Commented MNL_Home.h
- Refactored Sort.h and .cpp

Change Log 12/05/2021 - Thomas
- Initial commit