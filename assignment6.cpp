/*
 * CS 311, Fall 2022 Assignment #6
 * Name: Brian Moye
 * 
 * Simulate a main memory of 1,024 words
 * where each word equals 4 bytes.
 * 
 * The simulated physical memory is word addressable, but
 * the programmer's view is a byte addressable memory.
*/

#include <iostream>
using namespace std;

const int   MEM_SIZE = 1024;
const int   WORD_SIZE = 4;

int         memory[MEM_SIZE];

int8_t  mread(int byteAddr);
bool    mwrite(int byteAddr, int8_t value);

int main()
{
    // write 'A' in selected addresses
    for (int i = 0; i < MEM_SIZE; i += 3)
        cout << "write 'A' @ " << i << (mwrite(i, 0x41) ? " OK " : "Fail") << endl;

    // dump memory
    for (int i = 0; i < MEM_SIZE; i++)
        cout << "read address " << i << " got [" << mread(i) << "]" << endl;

    return 0;
}

// return the byte located at byte address "byteAddr"
int8_t mread(int byteAddr)
{
  int8_t data = 0;
  if(byteAddr < MEM_SIZE*WORD_SIZE)
  {
    int data_offset = (byteAddr & 0x3)<<3;
    int addy = byteAddr >> 2;
    data = static_cast<int8_t>(memory[addy]>>data_offset);
  }
  return data;
}

// write the byte value at byte address "byteAddr"
bool mwrite(int byteAddr, int8_t value)
{
  bool success = false;
  if (byteAddr < MEM_SIZE*WORD_SIZE)
  {
    int data_offset = (byteAddr & 0x3)<<3;
    int addy = byteAddr >> 2;
    int data = (static_cast<int>(value) << data_offset) | memory[addy];
    
    memory[addy] = data;
    success = true;
  }
    
  return success;
}

/*
2.
    a) Why do modern computers typically organize physical memory into words?
        Byte addressing would require more addresses, because each byte must be assigned an address 
        and if it were byte addressed it must support byte transfer, which has worse performance than
        a larger word transfer.

    b) Why is the programmer’s view of memory usually byte addressable?
        Byte addressable memory allows programmer's to easily access small data items such as characters.
    c) What can programmers do in their source code to improve memory performance
        Aligning data on boundaries that correspond to physical word size can improve program performance.
*/