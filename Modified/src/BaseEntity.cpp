#include "Arduino.h"
#include "BaseEntity.h"

int BaseEntity::m_iNextValidID = 0;

//----------------------------- SetID -----------------------------------------
//
//  this must be called within each constructor to make sure the ID is set
//  correctly. It verifies that the value passed to the method is greater
//  or equal to the next valid ID, before setting the ID and incrementing
//  the next valid ID
//-----------------------------------------------------------------------------
void BaseEntity::SetID(int val)
{
  // make sure the val is equal to or greater than the next available ID
  //  assert ( (val >= m_iNextValidID) && "<BaseEntity::SetID>: invalid ID");
  if (val >= m_iNextValidID)
    Serial.println("<BaseEntity::SetID>: invalid ID");
    
  m_ID = val;

  m_iNextValidID = m_ID + 1;
}
