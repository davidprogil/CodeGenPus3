# Rashid-3 NAV-C - OBC Interface Data Specificaiton

## Introduction

This document specifies the data interface between NAV-C and OBC of the Rashid-3 rover.

### Interface identification
TODO
### Interface general behaviour
TODO<br>



## Data Definition
### Packets Definition
#### SuccessReport
Packet ID: 0x0101<br>
Description: Acknowledge Acceptance Success - This TM is dispatched when a TC has been successfully received (the TC must have had its ACK
acceptance bit set).<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTmSecondaryHeader Type: [PUS_TmSecondaryHeader](#pus_tmsecondaryheader)<br>

- Name: pusAcceptanceReport Type: [PUS_AcceptanceReport](#pus_acceptancereport)<br>

<br>

#### FailReport
Packet ID: 0x0102<br>
Description: Acknowledge Acceptance Failure - This TM is dispatched when a TC has been rejected, regardless of its ACK settings. For instance due to bad CRC<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTmSecondaryHeader Type: [PUS_TmSecondaryHeader](#pus_tmsecondaryheader)<br>

- Name: pusAcceptanceReport Type: [PUS_AcceptanceReport](#pus_acceptancereport)<br>

- Name: failureId Type: uint16<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumFid](#enumfid)<br>

- Name: failureInfo Type: [variable](#variable)<br>
this field content depends on the type indicated by failureId<br>
,
<br>

#### SuccessExecutionReport
Packet ID: 0x0107<br>
Description: Acknowledge Execution Success - This TM is dispatched when a TC has been successfully executed (the TC must have had its ACK
execution bit set).<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTmSecondaryHeader Type: [PUS_TmSecondaryHeader](#pus_tmsecondaryheader)<br>

- Name: pusAcceptanceReport Type: [PUS_AcceptanceReport](#pus_acceptancereport)<br>

<br>

#### FailExecutionReport
Packet ID: 0x0108<br>
Description: Acknowledge Execution Failure - This TM is dispatched when a TC has been accepted but hasn’t been successfully executed, regardless
of its ACK settings.<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTmSecondaryHeader Type: [PUS_TmSecondaryHeader](#pus_tmsecondaryheader)<br>

- Name: pusAcceptanceReport Type: [PUS_AcceptanceReport](#pus_acceptancereport)<br>

- Name: failureId Type: uint16<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumFid](#enumfid)<br>

- Name: failureInfo Type: [variable](#variable)<br>
this field content depends on the type indicated by failureId<br>
,
<br>

#### HkReportEnable
Packet ID: 0x0305<br>
Description: Enable the Periodic Generation of Housekeeping Parameter Reports<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTcSecondaryHeader Type: [PUS_TcSecondaryHeader](#pus_tcsecondaryheader)<br>

- Name: numberOfRequests Type: uint8<br>
The value in this field has restrictions:<br>
Fixed Value: 1<br>

- Name: structureId Type: uint16<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumHkReportId](#enumhkreportid)<br>

<br>

#### HkReportDisable
Packet ID: 0x0306<br>
Description: Disable the Periodic Generation of Housekeeping Parameter Reports<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTcSecondaryHeader Type: [PUS_TcSecondaryHeader](#pus_tcsecondaryheader)<br>

- Name: numberOfRequests Type: uint8<br>
The value in this field has restrictions:<br>
Fixed Value: 1<br>

- Name: structureId Type: uint16<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumHkReportId](#enumhkreportid)<br>

<br>

#### HkReport
Packet ID: 0x0319<br>
Description: Informative Event<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTmSecondaryHeader Type: [PUS_TmSecondaryHeader](#pus_tmsecondaryheader)<br>

- Name: structureId Type: uint16<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumHkReportId](#enumhkreportid)<br>

- Name: hkData Type: [variable](#variable)<br>
this field content depends on the type indicated by structureId<br>
,
<br>

#### HkGenerate
Packet ID: 0x031B<br>
Description: Generate a One Shot Report for Housekeeping Parameter Report Structures<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTcSecondaryHeader Type: [PUS_TcSecondaryHeader](#pus_tcsecondaryheader)<br>

- Name: numberOfRequests Type: uint8<br>
The value in this field has restrictions:<br>
Fixed Value: 1<br>

- Name: structureId Type: uint16<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumHkReportId](#enumhkreportid)<br>

<br>

#### HkChangePeriod
Packet ID: 0x031F<br>
Description: This Telecommand modifies the collection interval of housekeeping parameter report structures<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTcSecondaryHeader Type: [PUS_TcSecondaryHeader](#pus_tcsecondaryheader)<br>

- Name: numberOfRequests Type: uint8<br>
The value in this field has restrictions:<br>
Fixed Value: 1<br>

- Name: structureId Type: uint16<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumHkReportId](#enumhkreportid)<br>

- Name: collectionInterval Type: uint16<br>

<br>

#### EventInformative
Packet ID: 0x0501<br>
Description: Informative Event<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTmSecondaryHeader Type: [PUS_TmSecondaryHeader](#pus_tmsecondaryheader)<br>

- Name: eventId Type: uint16<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumEventId](#enumeventid)<br>

- Name: eventInfo Type: [variable](#variable)<br>
this field content depends on the type indicated by eventId<br>
,
<br>

#### EventLowSeverity
Packet ID: 0x0502<br>
Description: Low-Severity Anomaly Report<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTmSecondaryHeader Type: [PUS_TmSecondaryHeader](#pus_tmsecondaryheader)<br>

- Name: eventId Type: uint16<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumEventId](#enumeventid)<br>

- Name: eventInfo Type: [variable](#variable)<br>
this field content depends on the type indicated by eventId<br>
,
<br>

#### EventMediumSeverity
Packet ID: 0x0503<br>
Description: Medium-Severity Anomaly Report<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTmSecondaryHeader Type: [PUS_TmSecondaryHeader](#pus_tmsecondaryheader)<br>

- Name: eventId Type: uint16<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumEventId](#enumeventid)<br>

- Name: eventInfo Type: [variable](#variable)<br>
this field content depends on the type indicated by eventId<br>
,
<br>

#### EventHighSeverity
Packet ID: 0x0504<br>
Description: High-Severity Anomaly Report<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTmSecondaryHeader Type: [PUS_TmSecondaryHeader](#pus_tmsecondaryheader)<br>

- Name: eventId Type: uint16<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumEventId](#enumeventid)<br>

- Name: eventInfo Type: [variable](#variable)<br>
this field content depends on the type indicated by eventId<br>
,
<br>

#### ExecuteFunction
Packet ID: 0x0801<br>
Description: Requests to start the execution of a given software function.<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTcSecondaryHeader Type: [PUS_TcSecondaryHeader](#pus_tcsecondaryheader)<br>

- Name: functionId Type: uint16<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumFunctionId](#enumfunctionid)<br>

- Name: functionParameters Type: [variable](#variable)<br>
this field content depends on the type indicated by functionId<br>
,
<br>

#### StopFunction
Packet ID: 0x0880<br>
Description: Stops the execution of an ongoing function.<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTcSecondaryHeader Type: [PUS_TcSecondaryHeader](#pus_tcsecondaryheader)<br>

- Name: functionId Type: uint16<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumFunctionId](#enumfunctionid)<br>

<br>

#### UpdateTime
Packet ID: 0x0984<br>
Description: The TC is used to provide a new coarse reference to the camera for its local on board time.<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTcSecondaryHeader Type: [PUS_TcSecondaryHeader](#pus_tcsecondaryheader)<br>

- Name: time Type: uint32<br>

- Name: unused Type: uint32<br>

<br>

#### ConnectionTest
Packet ID: 0x1101<br>
Description: This is the ping part of a ping-pong mechanism used to evaluate the responsive of the software<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTcSecondaryHeader Type: [PUS_TcSecondaryHeader](#pus_tcsecondaryheader)<br>

<br>

#### ConnectionReport
Packet ID: 0x1102<br>
Description: This is the response to TC(17,1) used to evaluate the responsive of the software<br>
Data Fields:<br>
- Name: primaryHeader Type: [PrimaryHeader](#primaryheader)<br>

- Name: pusTmSecondaryHeader Type: [PUS_TmSecondaryHeader](#pus_tmsecondaryheader)<br>

<br>



### Structure Types
#### PrimaryHeader
Data Fields:<br>
- Name: sequenceCounter Type: uint16<br>

<br>

#### UnexpectedValueUint16
Data Fields:<br>
- Name: expectedValue Type: uint16<br>

- Name: foundValue Type: uint16<br>

<br>

#### InvalidParameterValue
Data Fields:<br>
- Name: parameterCounter Type: uint16<br>

<br>

#### HkHeartBeat
Data Fields:<br>
- Name: upTime Type: uint32<br>

- Name: onboardTime Type: uint32<br>

- Name: mode Type: uint8<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumMode](#enummode)<br>

- Name: processesNo Type: uint16<br>

- Name: freeMemory Type: uint32<br>

- Name: freeSpace Type: uint32<br>

- Name: cpuLoad Type: float32<br>

- Name: socTempC Type: float32<br>

- Name: inputVoltageV Type: float32<br>

- Name: rail1o0V Type: float32<br>

- Name: rail1o0PfV Type: float32<br>

- Name: rail1o2V Type: float32<br>

- Name: rail1o8V Type: float32<br>

- Name: rail1o8PfV Type: float32<br>

- Name: rail2o5V Type: float32<br>

- Name: rail2o5VPf Type: float32<br>

- Name: rail3o3V Type: float32<br>

- Name: systemDdrV Type: float32<br>

- Name: FabricDdrV Type: float32<br>

- Name: adc1V Type: float32<br>

- Name: adc2V Type: float32<br>

- Name: cam1ThermistorOhm Type: float32<br>

- Name: cam2ThermistorOhm Type: float32<br>

- Name: cam1V Type: float32<br>

- Name: cam2V Type: float32<br>

- Name: camsTelemV Type: float32<br>

- Name: adcTel Type: float32<br>

- Name: sig1TempHighReached Type: uint8<br>

- Name: sig2TempLowReached Type: uint8<br>

- Name: sig3Clock Type: uint8<br>

<br>

#### HkNavigation
Data Fields:<br>
- Name: positionX Type: float32<br>

- Name: positionY Type: float32<br>

- Name: positionZ Type: float32<br>

- Name: isPositionValid Type: uint8<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumBoolean](#enumboolean)<br>

- Name: velocitiyX Type: float32<br>

- Name: velocitiyY Type: float32<br>

- Name: velocitiyZ Type: float32<br>

- Name: isVelocityValid Type: uint8<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumBoolean](#enumboolean)<br>

- Name: pitchAngle Type: float32<br>

- Name: rollAngle Type: float32<br>

- Name: yawAngle Type: float32<br>

- Name: isAttitudeValid Type: uint8<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumBoolean](#enumboolean)<br>

<br>

#### DeathReport
Data Fields:<br>
- Name: bootCounter Type: uint32<br>

- Name: rebootReason Type: uint8<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumRebootReason](#enumrebootreason)<br>

<br>

#### FunctionId
Data Fields:<br>
- Name: functionId Type: uint16<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumFunctionId](#enumfunctionid)<br>

<br>

#### Mode
Data Fields:<br>
- Name: mode Type: uint8<br>
The value in this field has restrictions:<br>
Value restricted by enumeration: [EnumMode](#enummode)<br>

<br>

#### MoveToPosition
Data Fields:<br>
- Name: positionX Type: float32<br>

- Name: positionY Type: float32<br>

- Name: velocitiy Type: float32<br>

<br>


### Other Data Types

#### PUS_TmSecondaryHeader 
Data Fields:
- Name: version Type: uint 4 bits Fixed Value: 1
- Name: scTimeReferenceStatus type: uint8 - Fixed Value: 0
- Name: serviceType Type: uint8 (Higher Part of packet ID)
- Name: serviceSubType Type: uint8 (Lower Part of packet ID)
- uint16_t messageTypeCounter;//per pid, per type/subtype, or 0 if not supported NOTS
- Name: destinationId type: uint16 - network address of TM issuer
- Name: time type: uint32 - time stamp of the TM
- Name: spare type: uint8 value ignored
 
#### PUS_TcSecondaryHeader
Data Fields:
- Name: version Type: uint 4 bits Fixed Value: 1
- Name: acknowledgementFlags Type: 4 bits, bit 3 = user requests successful acknowledgment bit 0 = user requests  successful end of execution
- Name: serviceType Type: uint8 (Higher Part of packet ID)
- Name: serviceSubType Type: uint8 (Lower Part of packet ID)
- Name: sourceId type: uint16 - network address of TC issuer
- Name: spare type: uint8 value ignored

### PUS_AcceptanceReport_t
Data Fields:
- Name: version Type: uint 3 bits Fixed Value: 1
- Name: packetType Type: 1 bit [EnumPktType](enumpktyype)
- Name: secondaryHeaderFlag Type: 1 bit Fixed Value: 1
- Name: sourceId Type: uint 11 bits- network address of TC issuer
- Name: sequenceFlags Type: 2 bits Always 0
- Name: packetSequenceCount: Type 14 bits - Sequence ID of the TC that is being responded to
	<br>



### Enumerations
#### EnumPktType
 Base type: uint8
 | Label | Value | associated type |
 |-------|-------|-----------------|
 |PKT_TELEMETRY|0|null|
 |PKT_TELECOMMAND|1|null|
<br>

#### EnumBoolean
 Base type: uint8
 | Label | Value | associated type |
 |-------|-------|-----------------|
 |BOL_FALSE|0|null|
 |BOL_TRUE|1|null|
<br>

#### EnumCspPort
 Base type: uint16
 | Label | Value | associated type |
 |-------|-------|-----------------|
 |CSPPORT_DATAHANDLING|32|null|
<br>

#### EnumFid
 Base type: uint16
 | Label | Value | associated type |
 |-------|-------|-----------------|
 |FID_OK|0|null|
 |FID_INVALID_PLENGTH|1|null|
 |FID_ILLEGAL_PUS_VERSION|2|null|
 |FID_CS_DISCREP|3|UnexpectedValueUint16|
 |FID_ILLEGAL_P_TYPE|4|null|
 |FID_LENGTH_DISCREP|5|UnexpectedValueUint16|
 |FID_INVALID_PARAMETER_VALUE|6|InvalidParameterValue|
 |FID_BUSY|7|null|
<br>

#### EnumHkReportId
 Base type: uint16
 | Label | Value | associated type |
 |-------|-------|-----------------|
 |HKID_ALL|0|null|
 |HKID_HEART_BEAT|1|HkHeartBeat|
 |HKID_NAVIGATION|2|HkNavigation|
<br>

#### EnumEventId
 Base type: uint16
 | Label | Value | associated type |
 |-------|-------|-----------------|
 |EID_MODE_CHANGE|0|Mode|
 |EID_SEQUENCE_START|1|FunctionId|
 |EID_SEQUENCE_END|2|FunctionId|
 |EID_SEQUENCE_ABORT|3|FunctionId|
 |EID_STORAGE_FAILURE|4|null|
 |EID_DEATH_REPORT|5|DeathReport|
<br>

#### EnumRebootReason
 Base type: uint8
 | Label | Value | associated type |
 |-------|-------|-----------------|
 |RS_UNKNOWN|0|null|
 |RS_COMMAND|1|null|
 |RS_POWER_ON|2|null|
 |RS_SW_ERROR|3|null|
<br>

#### EnumFunctionId
 Base type: uint16
 | Label | Value | associated type |
 |-------|-------|-----------------|
 |FUN_REBOOT_BOARD|0|null|
 |FUN_RESET_SOFTWARE|1|ApidStructure|
 |FUN_MODE_SAFE|13|null|
 |FUN_MODE_SCIENCE|14|null|
 |FUN_MODE_AUTONOMY1|15|null|
 |FUN_MODE_AUTONOMY2|16|null|
 |FUN_MODE_AUTONOMY3|17|null|
 |FUN_MODE_AUTONOMY4|18|null|
 |FUN_MOVE_TO_POSITION|19|MoveToPosition|
<br>

#### EnumMode
 Base type: uint8
 | Label | Value | associated type |
 |-------|-------|-----------------|
 |MODE_SAFE|0|null|
 |MODE_SCIENCE|1|null|
 |MODE_AUTONOMY1|2|null|
 |MODE_AUTONOMY2|3|null|
 |MODE_AUTONOMY3|4|null|
 |MODE_AUTONOMY4|5|null|
<br>


