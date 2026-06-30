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
#include <ASW_DeserializersUser.h>

/* macros-------------------------------------------------------------*/
/* none */

/* macros-------------------------------------------------------------*/
/* none */

/* types-------------------------------------------------------------*/
/* none */

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions-------------------------------------------------------------*/
ASW_DeserializerFunction_t *ASWD_GetDeserializerFunction(uint16_t packetId);
ASW_DeserializerFunction_t ASWD_DeserializeSuccessReport;
ASW_DeserializerFunction_t ASWD_DeserializeFailReport;
ASW_DeserializerFunction_t ASWD_DeserializeSuccessExecutionReport;
ASW_DeserializerFunction_t ASWD_DeserializeFailExecutionReport;
ASW_DeserializerFunction_t ASWD_DeserializeHkReportEnable;
ASW_DeserializerFunction_t ASWD_DeserializeHkReportDisable;
ASW_DeserializerFunction_t ASWD_DeserializeHkReport;
ASW_DeserializerFunction_t ASWD_DeserializeHkGenerate;
ASW_DeserializerFunction_t ASWD_DeserializeHkChangePeriod;
ASW_DeserializerFunction_t ASWD_DeserializeEventInformative;
ASW_DeserializerFunction_t ASWD_DeserializeEventLowSeverity;
ASW_DeserializerFunction_t ASWD_DeserializeEventMediumSeverity;
ASW_DeserializerFunction_t ASWD_DeserializeEventHighSeverity;
ASW_DeserializerFunction_t ASWD_DeserializeExecuteFunction;
ASW_DeserializerFunction_t ASWD_DeserializeStopFunction;
ASW_DeserializerFunction_t ASWD_DeserializeUpdateTime;
ASW_DeserializerFunction_t ASWD_DeserializeConnectionTest;
ASW_DeserializerFunction_t ASWD_DeserializeConnectionReport;
ASW_DeserializerFunction_t ASWD_DeserializeSetMode;
ASW_DeserializerFunction_t ASWD_DeserializeSetPictureParameters;
ASW_DeserializerFunction_t ASWD_DeserializeSetCameraParameters;
ASW_DeserializerFunction_t ASWD_DeserializeSetSequenceParameters;
ASW_DeserializerFunction_t ASWD_DeserializeSaveParameters;
ASW_DeserializerFunction_t ASWD_DeserializeClearParameters;
ASW_DeserializerFunction_t ASWD_DeserializeImageMetadata;
ASW_DeserializerFunction_t ASWD_DeserializeImageSegment;
ASW_DeserializerFunction_t ASWD_DeserializeGetSequenceParametersValue;
ASW_DeserializerFunction_t ASWD_DeserializeSequenceParametersValue;
ASW_DeserializerFunction_t ASWD_DeserializeClearImageStorage;

#endif
