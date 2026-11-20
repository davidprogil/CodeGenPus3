cmake ./src/
cmake --build .
./generatorFillers
./generatorSerializers
./generatorDeserializers
./generatorValidators
./generatorPrinters
cp ASW_Fillers.h 		../dpu-fos/server/aswPackets/include/ASW_Fillers.h
cp Fillers.c 			../dpu-fos/server/aswPackets/src/Fillers.c
cp ASW_Serializers.h 	../dpu-fos/server/aswPackets/include/ASW_Serializers.h
cp Serializers.c 		../dpu-fos/server/aswPackets/src/Serializers.c
cp ASW_Deserializers.h 	../dpu-fos/server/aswPackets/include/ASW_Deserializers.h
cp Deserializers.c 		../dpu-fos/server/aswPackets/src/Deserializers.c
cp ASW_Validators.h 	../dpu-fos/server/aswPackets/include/ASW_Validators.h
cp Validators.c 		../dpu-fos/server/aswPackets/src/Validators.c
cp ASW_Printers.h 		../dpu-fos/server/aswPackets/include