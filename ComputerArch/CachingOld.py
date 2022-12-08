
r0 = 0
r1 = 0
r2 = 0
r3 = 0

Data_TableX = 0x1000
Dat_Len = 0xFF
Dat_List = [0x05, 0x06, 0x0E, 0x0F, 0x16, 0x17, 0x18, 0x1F, 0x20, 0x28, 0x29, 0x30, 0x31, 0x39, 0x3A, 0x41, 0x42, 0x4A, 0x4B, 0x52, 0x53, 0x54, 0x5B, 0x5C, 0x64, 0x65, 0x6C, 0x6D, 0x75, 0x76, 0x7D,
            0x7E, 0x86, 0x87, 0x8E, 0x8F, 0x90, 0x97, 0x98, 0xA0, 0xA1, 0xA8, 0xA9, 0xB1, 0xB2, 0xB9, 0xBA, 0xC2, 0xC3, 0xCA, 0xCB, 0xD3, 0xD4, 0xDB, 0xDC, 0xDD, 0xE4, 0xE5, 0xED, 0xEE, 0xF5, 0xF6, 0xFE, 0xFF]

Input_TableX = 0x0100
Input_List = [1, 0x1F]

Output_TableX = 0x0200
Output_List = []

Stack = 0xDFFF
Var = 0xA000

Len_Input = 0
Index_Input = 0
Len_Output = 0
Index_Output = 0
Start_Dat = 0
Current_Dat = 0
Final_Dat = 0

Len_InputX = 0xA000
Index_InputX = 0xA001
Len_OutputX = 0xA002
Index_OutputX = 0xA003
Start_DatX = 0xA010
Current_DatX = 0xA011
Final_DatX = 0xA012

Program_Counter = 0xF000
Cache_List = [0xF000]


def Data_to_cache(Hex):
    Cache_List.append(Hex)


def PC_to_cache(HexLen):
    i = 0
    global Program_Counter
    while i < HexLen:
        Program_Counter += 1
        Cache_List.append(Program_Counter)
        i += 1


def Jump_Program(Hex):
    Program_Counter = Hex


def printCache():
    global Cache_List
    length = len(Cache_List)
    i = 0
    printer = ""
    while i < length:
        printer = printer + hex(Cache_List[i]) + ","
        i += 1
    print(printer[:-1])
    Cache_List = Cache_List[-1:-1]


def Start_Dat():
    PC_to_cache(3)
    Data_to_cache(Input_TableX)
    r0 = Input_TableX
    PC_to_cache(5)
    printCache()


def Initt():
    global r0
    r0 = 0
    PC_to_cache(2)
    global Len_Output
    Len_Output = r0
    global Index_Input
    global Index_Output
    r0 += 1
    PC_to_cache(3)
    Data_to_cache(Len_OutputX)
    PC_to_cache(3)
    PC_to_cache(2)
    Index_Input = r0
    Data_to_cache(Index_InputX)
    PC_to_cache(3)
    Index_Output = r0
    Data_to_cache(Index_OutputX)
    printCache()


def GET_INPUT_DATA_VALUE():
    global r1, r0
    r1 = Input_List[r0]
    PC_to_cache(3)
    Data_to_cache((Input_TableX//256) + r0)
    r0 = 64
    PC_to_cache(4)
    Data_to_cache(Data_TableX + 0xff)
    r0 -= 1
    PC_to_cache(2)
    global Final_Dat
    Final_Dat = r0
    PC_to_cache(3)
    Data_to_cache(Final_DatX)
    r0 = 0
    PC_to_cache(2)

    global Start_Dat
    Start_Dat = r0
    PC_to_cache(4)
    Data_to_cache(Start_DatX)

    global Current_Dat
    Current_Dat = r0
    PC_to_cache(4)
    Data_to_cache(Current_DatX)
    PC_to_cache(3)
    Data_to_cache(Data_TableX)
    if r1 == Dat_List[0]:
        print(str(r1) + " == " + str(Dat_List[0]))
        PC_to_cache(3)
        Jump_Program(0xF05D)
        printCache()
        DATA_FOUND()
    elif r1 > Dat_List[0]:
        print(str(r1) + " > " + str(Dat_List[0]))
        PC_to_cache(6)
        Jump_Program(0xF052)
        printCache()
        NOT_FOUND()
    else:
        pass



def DATA_FOUND():
    global r2,Index_Output
    r2 = Index_Output
    PC_to_cache(4)
    Data_to_cache(Index_OutputX)
    
    
    pass


def NOT_FOUND():
    pass


Start_Dat()
Initt()
GET_INPUT_DATA_VALUE()
