/*********************************************************************
 * @fn      		  - I2C_MasterReceiveDataIT
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              - Complete the below code . Also include the fn prototype in header file

 */
uint8_t I2C_MasterReceiveDataIT(I2C_Handle_t *pI2CHandle,uint8_t *pRxBuffer, uint32_t Len, uint8_t SlaveAddr,uint8_t Sr)
{

	uint8_t busystate = pI2CHandle->?;

	if( (busystate != I2C_BUSY_IN_TX) && (busystate != I2C_BUSY_IN_RX))
	{
		pI2CHandle->pRxBuffer = ?;
		pI2CHandle->RxLen = ?;
		pI2CHandle->TxRxState = ?;
		pI2CHandle->RxSize = Len; //Rxsize is used in the ISR code to manage the data reception 
		pI2CHandle->DevAddr = ?;
		pI2CHandle->Sr = Sr;

		//Implement code to Generate START Condition
		

		//Implement the code to enable ITBUFEN Control Bit
		

		//Implement the code to enable ITEVFEN Control Bit
		

		//Implement the code to enable ITERREN Control Bit
		
	}

	return busystate;
}