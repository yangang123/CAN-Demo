/*
 * can_handler.c
 *
 *  Created on: 23.05.2015
 *      Author: Abhijeet
 */

#include "can_handler.h"
#include "can.h"

void can_handler_init()
{
	CAN_Init( ((2) << 12)  	 |		//BRP
			  ((3) << 8) 	 |	 	//SJW
			  ((0) << 6)   	 |		//TSEG1
			  ((1)) 				//TSEG2
			);			//set baud rate of 500kbps

	NVIC_EnableIRQ(CAN_IRQn);
}

void can_handler_send(uint32_t msg_id, uint32_t dlc, uint32_t *data )
{
	uint8_t msg_no=1;
	uint8_t received_flag=0;
	uint32_t can_packet[6];
	uint8_t packet_cnt=0;


	can_packet[packet_cnt++] = msg_id;
	can_packet[packet_cnt++] = dlc;

	can_packet[packet_cnt++] = *data++;
	can_packet[packet_cnt++] = *data++;
	can_packet[packet_cnt++] = *data++;
	can_packet[packet_cnt++] = *data++;


	CAN_Send(msg_no, received_flag, can_packet);


}
void can_handler_receive()
{

}


