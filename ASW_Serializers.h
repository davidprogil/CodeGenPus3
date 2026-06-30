/*******************************************************************************/
/* Copyright XXXXXXXXX 1998-YYYY                                               */
/*                                                                             */
/* xxxxxxxx@xxxxx.xxx                                                          */
/*******************************************************************************/

#ifndef ASWF_Serializers_H
#define ASWF_Serializers_H

/* system includes-------------------------------------------------------------*/
/* none */
/* application includes-------------------------------------------------------------*/
#include <myTypes.h>
/* component includes-------------------------------------------------------------*/
#include <ASW_Fillers.h>
#include <ASW_SerializersUser.h>

/* macros-------------------------------------------------------------*/
/* none */

/* macros-------------------------------------------------------------*/
/* none */

/* types-------------------------------------------------------------*/
/* none */

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions-------------------------------------------------------------*/
bool_t ASWS_SerializeSuccessReport(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_SuccessReport_t *structuredData);
bool_t ASWS_SerializeFailReport(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_FailReport_t *structuredData);
bool_t ASWS_SerializeSuccessExecutionReport(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_SuccessExecutionReport_t *structuredData);
bool_t ASWS_SerializeFailExecutionReport(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_FailExecutionReport_t *structuredData);
bool_t ASWS_SerializeHkReportEnable(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_HkReportEnable_t *structuredData);
bool_t ASWS_SerializeHkReportDisable(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_HkReportDisable_t *structuredData);
bool_t ASWS_SerializeHkReport(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_HkReport_t *structuredData);
bool_t ASWS_SerializeHkGenerate(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_HkGenerate_t *structuredData);
bool_t ASWS_SerializeHkChangePeriod(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_HkChangePeriod_t *structuredData);
bool_t ASWS_SerializeEventInformative(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_EventInformative_t *structuredData);
bool_t ASWS_SerializeEventLowSeverity(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_EventLowSeverity_t *structuredData);
bool_t ASWS_SerializeEventMediumSeverity(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_EventMediumSeverity_t *structuredData);
bool_t ASWS_SerializeEventHighSeverity(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_EventHighSeverity_t *structuredData);
bool_t ASWS_SerializeExecuteFunction(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_ExecuteFunction_t *structuredData);
bool_t ASWS_SerializeStopFunction(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_StopFunction_t *structuredData);
bool_t ASWS_SerializeUpdateTime(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_UpdateTime_t *structuredData);
bool_t ASWS_SerializeConnectionTest(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_ConnectionTest_t *structuredData);
bool_t ASWS_SerializeConnectionReport(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_ConnectionReport_t *structuredData);
bool_t ASWS_SerializeSetMode(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_SetMode_t *structuredData);
bool_t ASWS_SerializeSetPictureParameters(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_SetPictureParameters_t *structuredData);
bool_t ASWS_SerializeSetCameraParameters(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_SetCameraParameters_t *structuredData);
bool_t ASWS_SerializeSetSequenceParameters(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_SetSequenceParameters_t *structuredData);
bool_t ASWS_SerializeSaveParameters(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_SaveParameters_t *structuredData);
bool_t ASWS_SerializeClearParameters(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_ClearParameters_t *structuredData);
bool_t ASWS_SerializeImageMetadata(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_ImageMetadata_t *structuredData);
bool_t ASWS_SerializeImageSegment(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_ImageSegment_t *structuredData);
bool_t ASWS_SerializeGetSequenceParametersValue(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_GetSequenceParametersValue_t *structuredData);
bool_t ASWS_SerializeSequenceParametersValue(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_SequenceParametersValue_t *structuredData);
bool_t ASWS_SerializeClearImageStorage(uint8_t *target, uint16_t targetNb, uint16_t *totalDataSize, ASW_ClearImageStorage_t *structuredData);

#endif
