/* Messenger.h
* 
* An implementation of a simple text chat only messenger on the tox network core.
* 
*/
 
 
#ifndef MESSENGER_H 
#define MESSENGER_H  

#include "net_crypto.h"
#include "DHT.h"


//add a friend
//returns the friend number if success
//return -1 if failure.
int m_addfriend(uint8_t * client_id);


//add a friend without sending a friendrequest.
//returns the friend number if success
//return -1 if failure.
int m_addfriend_norequest(uint8_t * client_id);

//return the friend id associated to that client id.
//return -1 if no such friend
int getfriend_id(uint8_t * client_id);

//remove a friend
int m_delfriend(int friendnumber);

//return 4 if friend is online
//return 3 if friend is confirmed
//return 2 if the friend request was sent
//return 1 if the friend was added
//return 0 if there is no friend with that number.
int m_friendstatus(int friendnumber);


//send a text chat message to an online friend.
//returns 1 if packet was successfully put into the send queue
//return 0 if it was not.
int m_sendmessage(int friendnumber, uint8_t * message, uint32_t length);

//set the data that will be sent along with friend requests
//return -1 if failure
//return 0 if success
int m_setinfo(uint8_t * data, uint16_t length);

//set the function that will be executed when a friend request is received.
//function format is function(uint8_t * public_key, uint8_t * data, uint16_t length)
void m_callback_friendrequest(void (*function)(uint8_t *, uint8_t *, uint16_t));


//set the function that will be executed when a message from a friend is received.
//function format is: function(int friendnumber, uint8_t * message, uint32_t length)
void m_callback_friendmessage(void (*function)(int, uint8_t *, uint16_t));


//run this at startup
void initMessenger();


//the main loop that needs to be run at least 200 times per second.
void doMessenger();

#endif