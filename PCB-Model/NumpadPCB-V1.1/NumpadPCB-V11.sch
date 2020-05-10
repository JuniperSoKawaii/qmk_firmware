EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Numpad PCB Schematic"
Date ""
Rev "1.1"
Comp "Carter Cocke"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L KeyboardParts:ATMEGA32U4 U1
U 1 1 5EAB2146
P 5700 2900
F 0 "U1" H 5725 4237 60  0000 C CNN
F 1 "ATMEGA32U4" H 5725 4131 60  0000 C CNN
F 2 "Package_QFP:TQFP-44-1EP_10x10mm_P0.8mm_EP4.5x4.5mm" H 5700 2900 60  0001 C CNN
F 3 "" H 5700 2900 60  0000 C CNN
	1    5700 2900
	1    0    0    -1  
$EndComp
$Comp
L KeyboardParts:XTAL_GND X1
U 1 1 5EAB86CB
P 3200 3700
F 0 "X1" H 3200 3992 60  0000 C CNN
F 1 "XTAL_GND" H 3200 3886 60  0000 C CNN
F 2 "KeyboardPartsPretty:FA-238" H 3200 3700 60  0001 C CNN
F 3 "" H 3200 3700 60  0000 C CNN
	1    3200 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 3700 2900 3700
Wire Wire Line
	3500 3700 3600 3700
Wire Wire Line
	3200 3900 3200 4100
Connection ~ 3200 4100
Wire Wire Line
	3200 4100 2800 4100
Wire Wire Line
	3200 4100 3600 4100
Wire Wire Line
	3600 3700 3600 3450
Wire Wire Line
	3600 3450 4650 3450
Wire Wire Line
	2800 3700 2800 3350
Wire Wire Line
	2800 3350 4650 3350
$Comp
L power:VCC #PWR0102
U 1 1 5EAC1E39
P 5000 800
F 0 "#PWR0102" H 5000 650 50  0001 C CNN
F 1 "VCC" H 5017 973 50  0000 C CNN
F 2 "" H 5000 800 50  0001 C CNN
F 3 "" H 5000 800 50  0001 C CNN
	1    5000 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 900  5000 800 
$Comp
L power:VCC #PWR0104
U 1 1 5EAD58F7
P 2850 2700
F 0 "#PWR0104" H 2850 2550 50  0001 C CNN
F 1 "VCC" V 2868 2827 50  0000 L CNN
F 2 "" H 2850 2700 50  0001 C CNN
F 3 "" H 2850 2700 50  0001 C CNN
	1    2850 2700
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R1
U 1 1 5EAD769F
P 3250 2700
F 0 "R1" V 3150 2700 50  0000 C CNN
F 1 "10k" V 3250 2700 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3250 2700 60  0001 C CNN
F 3 "" H 3250 2700 60  0000 C CNN
	1    3250 2700
	0    1    1    0   
$EndComp
$Comp
L KeyboardParts:SW_PUSH SW1
U 1 1 5EAD87A5
P 3250 2950
F 0 "SW1" H 3250 2900 50  0000 C CNN
F 1 "SW_PUSH" H 3250 3100 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_TL3342" H 3250 2950 60  0001 C CNN
F 3 "" H 3250 2950 60  0000 C CNN
	1    3250 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 2700 3550 2700
Wire Wire Line
	3000 2700 2850 2700
$Comp
L KeyboardParts:R R2
U 1 1 5EADD59D
P 7100 2950
F 0 "R2" V 7100 2850 50  0000 C CNN
F 1 "10k" V 7100 3000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7100 2950 60  0001 C CNN
F 3 "" H 7100 2950 60  0000 C CNN
	1    7100 2950
	0    1    1    0   
$EndComp
$Comp
L Connector:USB_C_Receptacle J1
U 1 1 5EAF0838
P 1300 2500
F 0 "J1" H 1300 3750 50  0000 C CNN
F 1 "USB_C_Receptacle" H 1300 3650 50  0000 C CNN
F 2 "Connector_USB:USB_C_Receptacle_Amphenol_12401548E4-2A" H 1450 2500 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 1450 2500 50  0001 C CNN
	1    1300 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 1500 3600 1500
Wire Wire Line
	3600 1500 3600 2450
Wire Wire Line
	3550 3050 4650 3050
Wire Wire Line
	1900 2100 1900 2050
$Comp
L KeyboardParts:R R5
U 1 1 5EB0FA29
P 2200 2050
F 0 "R5" V 2200 2000 50  0000 C CNN
F 1 "22" V 2200 2150 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2200 2050 60  0001 C CNN
F 3 "" H 2200 2050 60  0000 C CNN
	1    2200 2050
	0    1    1    0   
$EndComp
$Comp
L KeyboardParts:R R6
U 1 1 5EB10CB0
P 2200 2250
F 0 "R6" V 2200 2200 50  0000 C CNN
F 1 "22" V 2200 2350 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2200 2250 60  0001 C CNN
F 3 "" H 2200 2250 60  0000 C CNN
	1    2200 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	1900 2300 1900 2250
Wire Wire Line
	1900 2250 1950 2250
Connection ~ 1900 2250
Wire Wire Line
	1900 2250 1900 2200
Wire Wire Line
	1900 2050 1950 2050
Connection ~ 1900 2050
Wire Wire Line
	1900 2050 1900 2000
Wire Wire Line
	2450 2250 2450 2150
Wire Wire Line
	2450 2150 4650 2150
Wire Wire Line
	2450 2050 4650 2050
$Comp
L KeyboardParts:R R3
U 1 1 5EB15288
P 2250 1700
F 0 "R3" V 2250 1800 50  0000 C CNN
F 1 "5.1k" V 2250 1650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2250 1700 60  0001 C CNN
F 3 "" H 2250 1700 60  0000 C CNN
	1    2250 1700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1900 1700 2000 1700
$Comp
L KeyboardParts:R R4
U 1 1 5EB1A2E9
P 2250 1800
F 0 "R4" V 2250 1900 50  0000 C CNN
F 1 "5.1k" V 2250 1750 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2250 1800 60  0001 C CNN
F 3 "" H 2250 1800 60  0000 C CNN
	1    2250 1800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1900 1800 2000 1800
Wire Wire Line
	3550 3200 3550 3050
Wire Wire Line
	3550 3050 3550 2950
Connection ~ 3550 3050
Wire Wire Line
	3550 2950 3550 2700
Connection ~ 3550 2950
Wire Wire Line
	2950 3200 2950 2950
Wire Wire Line
	1300 4100 2350 4100
$Comp
L Device:C_Small C8
U 1 1 5EB377BC
P 5000 1100
F 0 "C8" H 5092 1146 50  0000 L CNN
F 1 "0.1u" H 5092 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5000 1100 50  0001 C CNN
F 3 "~" H 5000 1100 50  0001 C CNN
	1    5000 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 900  5350 900 
Wire Wire Line
	5000 1300 5350 1300
$Comp
L Device:C_Small C3
U 1 1 5EB38F24
P 5350 1100
F 0 "C3" H 5442 1146 50  0000 L CNN
F 1 "0.1u" H 5442 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5350 1100 50  0001 C CNN
F 3 "~" H 5350 1100 50  0001 C CNN
	1    5350 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C5
U 1 1 5EB399EE
P 5700 1100
F 0 "C5" H 5792 1146 50  0000 L CNN
F 1 "0.1u" H 5792 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5700 1100 50  0001 C CNN
F 3 "~" H 5700 1100 50  0001 C CNN
	1    5700 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5EB39D7D
P 6050 1100
F 0 "C4" H 6142 1146 50  0000 L CNN
F 1 "0.1u" H 6142 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6050 1100 50  0001 C CNN
F 3 "~" H 6050 1100 50  0001 C CNN
	1    6050 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C6
U 1 1 5EB3C3CA
P 6400 1100
F 0 "C6" H 6492 1146 50  0000 L CNN
F 1 "4.7u" H 6492 1055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6400 1100 50  0001 C CNN
F 3 "~" H 6400 1100 50  0001 C CNN
	1    6400 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 1300 5000 1200
Wire Wire Line
	5000 1000 5000 900 
Connection ~ 5000 900 
Wire Wire Line
	5350 1000 5350 900 
Connection ~ 5350 900 
Wire Wire Line
	5350 900  5700 900 
Wire Wire Line
	5350 1200 5350 1300
Connection ~ 5350 1300
Wire Wire Line
	5350 1300 5700 1300
Wire Wire Line
	5700 1200 5700 1300
Connection ~ 5700 1300
Wire Wire Line
	5700 1300 6050 1300
Wire Wire Line
	5700 1000 5700 900 
Connection ~ 5700 900 
Wire Wire Line
	5700 900  6050 900 
Wire Wire Line
	6050 1000 6050 900 
Connection ~ 6050 900 
Wire Wire Line
	6050 900  6400 900 
Wire Wire Line
	6050 1200 6050 1300
Connection ~ 6050 1300
Wire Wire Line
	6050 1300 6400 1300
Wire Wire Line
	6400 1200 6400 1300
Wire Wire Line
	6400 1000 6400 900 
$Comp
L Device:C_Small C1
U 1 1 5EB46793
P 2800 3900
F 0 "C1" H 2892 3946 50  0000 L CNN
F 1 "22p" H 2892 3855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2800 3900 50  0001 C CNN
F 3 "~" H 2800 3900 50  0001 C CNN
	1    2800 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5EB4731A
P 3600 3900
F 0 "C2" H 3692 3946 50  0000 L CNN
F 1 "22p" H 3692 3855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3600 3900 50  0001 C CNN
F 3 "~" H 3600 3900 50  0001 C CNN
	1    3600 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 3800 3600 3700
Connection ~ 3600 3700
Wire Wire Line
	3600 4100 3600 4000
Wire Wire Line
	2800 4100 2800 4000
Wire Wire Line
	2800 3800 2800 3700
Connection ~ 2800 3700
$Comp
L Device:C_Small C9
U 1 1 5EB4C793
P 3250 3200
F 0 "C9" V 3150 3100 50  0000 C CNN
F 1 ".1u" V 3150 3300 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3250 3200 50  0001 C CNN
F 3 "~" H 3250 3200 50  0001 C CNN
	1    3250 3200
	0    1    1    0   
$EndComp
Wire Wire Line
	2950 3200 3150 3200
Wire Wire Line
	3350 3200 3550 3200
$Comp
L Device:C_Small C7
U 1 1 5EB5410F
P 4450 2350
F 0 "C7" V 4400 2250 50  0000 C CNN
F 1 "1.0u" V 4400 2450 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4450 2350 50  0001 C CNN
F 3 "~" H 4450 2350 50  0001 C CNN
	1    4450 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	4550 2350 4650 2350
Wire Wire Line
	4200 2250 4250 2250
Wire Wire Line
	4250 2350 4250 2250
Wire Wire Line
	4250 2350 4350 2350
Connection ~ 4250 2250
Wire Wire Line
	4250 2250 4650 2250
Wire Wire Line
	4250 2350 2350 2350
Connection ~ 4250 2350
Wire Wire Line
	2350 2350 2350 4100
Wire Wire Line
	3600 2450 4650 2450
NoConn ~ 1900 3800
NoConn ~ 1900 3700
NoConn ~ 1900 3500
NoConn ~ 1900 3400
NoConn ~ 1900 3200
NoConn ~ 1900 3100
NoConn ~ 1900 2900
NoConn ~ 1900 2800
NoConn ~ 1900 2600
NoConn ~ 1900 2500
$Comp
L power:VCC #PWR0110
U 1 1 5EB74560
P 4500 3150
F 0 "#PWR0110" H 4500 3000 50  0001 C CNN
F 1 "VCC" V 4518 3277 50  0000 L CNN
F 2 "" H 4500 3150 50  0001 C CNN
F 3 "" H 4500 3150 50  0001 C CNN
	1    4500 3150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4500 3150 4650 3150
$Comp
L power:VCC #PWR0111
U 1 1 5EB76751
P 7000 3850
F 0 "#PWR0111" H 7000 3700 50  0001 C CNN
F 1 "VCC" V 7017 3978 50  0000 L CNN
F 2 "" H 7000 3850 50  0001 C CNN
F 3 "" H 7000 3850 50  0001 C CNN
	1    7000 3850
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0112
U 1 1 5EB77973
P 7000 2850
F 0 "#PWR0112" H 7000 2700 50  0001 C CNN
F 1 "VCC" V 7000 3000 50  0000 L CNN
F 2 "" H 7000 2850 50  0001 C CNN
F 3 "" H 7000 2850 50  0001 C CNN
	1    7000 2850
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0113
U 1 1 5EB789DA
P 7000 1850
F 0 "#PWR0113" H 7000 1700 50  0001 C CNN
F 1 "VCC" V 7000 2000 50  0000 L CNN
F 2 "" H 7000 1850 50  0001 C CNN
F 3 "" H 7000 1850 50  0001 C CNN
	1    7000 1850
	0    1    1    0   
$EndComp
Wire Wire Line
	7000 1850 6800 1850
Wire Wire Line
	7000 2850 6800 2850
Wire Wire Line
	7000 3850 6800 3850
$Comp
L KeyboardParts:KEYSW K1
U 1 1 5EB8CDB1
P 8350 1450
F 0 "K1" H 8350 1450 60  0000 C CNN
F 1 "KEYSW" H 8350 1350 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 8350 1450 60  0001 C CNN
F 3 "" H 8350 1450 60  0000 C CNN
	1    8350 1450
	1    0    0    -1  
$EndComp
$Comp
L KeyboardParts:D D1
U 1 1 5EACBA03
P 7950 1700
F 0 "D1" H 7822 1650 60  0000 R CNN
F 1 "D" V 8100 1650 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 7950 1700 60  0001 C CNN
F 3 "" H 7950 1700 60  0000 C CNN
	1    7950 1700
	-1   0    0    1   
$EndComp
Wire Wire Line
	8650 1450 8650 1300
Wire Wire Line
	7950 1550 7950 1450
Wire Wire Line
	7950 1450 8050 1450
Wire Wire Line
	7950 1750 7950 1850
$Comp
L KeyboardParts:KEYSW K2
U 1 1 5EAE0DA7
P 9150 1450
F 0 "K2" H 9150 1450 60  0000 C CNN
F 1 "KEYSW" H 9150 1350 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 9150 1450 60  0001 C CNN
F 3 "" H 9150 1450 60  0000 C CNN
	1    9150 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 1450 9450 1300
Wire Wire Line
	8750 1550 8750 1450
Wire Wire Line
	8750 1450 8850 1450
Wire Wire Line
	9550 1850 9550 1750
Wire Wire Line
	8750 1850 9550 1850
Wire Wire Line
	7950 1850 8750 1850
Wire Wire Line
	8750 1850 8750 1750
$Comp
L KeyboardParts:D D2
U 1 1 5EAE0DAD
P 8750 1700
F 0 "D2" H 8622 1650 60  0000 R CNN
F 1 "D" V 8900 1650 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 8750 1700 60  0001 C CNN
F 3 "" H 8750 1700 60  0000 C CNN
	1    8750 1700
	-1   0    0    1   
$EndComp
Connection ~ 8750 1850
$Comp
L KeyboardParts:KEYSW K3
U 1 1 5EAEE9AA
P 9950 1450
F 0 "K3" H 9950 1450 60  0000 C CNN
F 1 "KEYSW" H 9950 1350 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 9950 1450 60  0001 C CNN
F 3 "" H 9950 1450 60  0000 C CNN
	1    9950 1450
	1    0    0    -1  
$EndComp
$Comp
L KeyboardParts:D D3
U 1 1 5EAEE9B0
P 9550 1700
F 0 "D3" H 9422 1650 60  0000 R CNN
F 1 "D" V 9700 1650 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 9550 1700 60  0001 C CNN
F 3 "" H 9550 1700 60  0000 C CNN
	1    9550 1700
	-1   0    0    1   
$EndComp
Wire Wire Line
	10250 1450 10250 1300
Wire Wire Line
	9550 1550 9550 1450
Wire Wire Line
	9550 1450 9650 1450
$Comp
L KeyboardParts:KEYSW K4
U 1 1 5EAEE9BA
P 10750 1450
F 0 "K4" H 10750 1450 60  0000 C CNN
F 1 "KEYSW" H 10750 1350 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 10750 1450 60  0001 C CNN
F 3 "" H 10750 1450 60  0000 C CNN
	1    10750 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	11050 1450 11050 1300
Wire Wire Line
	10350 1550 10350 1450
Wire Wire Line
	10350 1450 10450 1450
Wire Wire Line
	9550 1850 10350 1850
Wire Wire Line
	10350 1850 10350 1750
$Comp
L KeyboardParts:D D4
U 1 1 5EAEE9C7
P 10350 1700
F 0 "D4" H 10222 1650 60  0000 R CNN
F 1 "D" V 10500 1650 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 10350 1700 60  0001 C CNN
F 3 "" H 10350 1700 60  0000 C CNN
	1    10350 1700
	-1   0    0    1   
$EndComp
$Comp
L KeyboardParts:KEYSW K5
U 1 1 5EAF9B05
P 8350 2050
F 0 "K5" H 8350 2050 60  0000 C CNN
F 1 "KEYSW" H 8350 1950 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 8350 2050 60  0001 C CNN
F 3 "" H 8350 2050 60  0000 C CNN
	1    8350 2050
	1    0    0    -1  
$EndComp
$Comp
L KeyboardParts:D D5
U 1 1 5EAF9B0B
P 7950 2300
F 0 "D5" H 7822 2250 60  0000 R CNN
F 1 "D" V 8100 2250 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 7950 2300 60  0001 C CNN
F 3 "" H 7950 2300 60  0000 C CNN
	1    7950 2300
	-1   0    0    1   
$EndComp
Wire Wire Line
	7950 2150 7950 2050
Wire Wire Line
	7950 2050 8050 2050
Wire Wire Line
	7950 2350 7950 2450
$Comp
L KeyboardParts:KEYSW K6
U 1 1 5EAF9B15
P 9150 2050
F 0 "K6" H 9150 2050 60  0000 C CNN
F 1 "KEYSW" H 9150 1950 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 9150 2050 60  0001 C CNN
F 3 "" H 9150 2050 60  0000 C CNN
	1    9150 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 2150 8750 2050
Wire Wire Line
	8750 2050 8850 2050
Wire Wire Line
	9550 2450 9550 2350
Wire Wire Line
	8750 2450 9550 2450
Wire Wire Line
	7950 2450 8750 2450
Wire Wire Line
	8750 2450 8750 2350
$Comp
L KeyboardParts:D D6
U 1 1 5EAF9B22
P 8750 2300
F 0 "D6" H 8622 2250 60  0000 R CNN
F 1 "D" V 8900 2250 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 8750 2300 60  0001 C CNN
F 3 "" H 8750 2300 60  0000 C CNN
	1    8750 2300
	-1   0    0    1   
$EndComp
Connection ~ 8750 2450
$Comp
L KeyboardParts:KEYSW K7
U 1 1 5EAF9B29
P 9950 2050
F 0 "K7" H 9950 2050 60  0000 C CNN
F 1 "KEYSW" H 9950 1950 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 9950 2050 60  0001 C CNN
F 3 "" H 9950 2050 60  0000 C CNN
	1    9950 2050
	1    0    0    -1  
$EndComp
$Comp
L KeyboardParts:D D7
U 1 1 5EAF9B2F
P 9550 2300
F 0 "D7" H 9422 2250 60  0000 R CNN
F 1 "D" V 9700 2250 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 9550 2300 60  0001 C CNN
F 3 "" H 9550 2300 60  0000 C CNN
	1    9550 2300
	-1   0    0    1   
$EndComp
Wire Wire Line
	9550 2150 9550 2050
$Comp
L KeyboardParts:KEYSW K8
U 1 1 5EAF9B38
P 10750 2050
F 0 "K8" H 10750 2050 60  0000 C CNN
F 1 "KEYSW" H 10750 1950 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 10750 2050 60  0001 C CNN
F 3 "" H 10750 2050 60  0000 C CNN
	1    10750 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 2150 10350 2050
Wire Wire Line
	10350 2050 10450 2050
Wire Wire Line
	9550 2450 10350 2450
Wire Wire Line
	10350 2450 10350 2350
$Comp
L KeyboardParts:D D8
U 1 1 5EAF9B45
P 10350 2300
F 0 "D8" H 10222 2250 60  0000 R CNN
F 1 "D" V 10500 2250 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 10350 2300 60  0001 C CNN
F 3 "" H 10350 2300 60  0000 C CNN
	1    10350 2300
	-1   0    0    1   
$EndComp
Wire Wire Line
	8650 1450 8650 2050
Connection ~ 8650 1450
Wire Wire Line
	9450 1450 9450 2050
Connection ~ 9450 1450
Wire Wire Line
	10250 1450 10250 2050
Connection ~ 10250 1450
Wire Wire Line
	11050 1450 11050 2050
Connection ~ 11050 1450
Wire Wire Line
	7950 1850 7850 1850
Connection ~ 7950 1850
Wire Wire Line
	7950 2450 7850 2450
Connection ~ 7950 2450
$Comp
L KeyboardParts:KEYSW K9
U 1 1 5EB2CA0C
P 8350 2650
F 0 "K9" H 8350 2650 60  0000 C CNN
F 1 "KEYSW" H 8350 2550 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 8350 2650 60  0001 C CNN
F 3 "" H 8350 2650 60  0000 C CNN
	1    8350 2650
	1    0    0    -1  
$EndComp
$Comp
L KeyboardParts:D D9
U 1 1 5EB2CA12
P 7950 3100
F 0 "D9" H 7822 3050 60  0000 R CNN
F 1 "D" V 8100 3050 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 7950 3100 60  0001 C CNN
F 3 "" H 7950 3100 60  0000 C CNN
	1    7950 3100
	-1   0    0    1   
$EndComp
Wire Wire Line
	7950 2650 8050 2650
Wire Wire Line
	7950 3150 7950 3250
$Comp
L KeyboardParts:KEYSW K10
U 1 1 5EB2CA1C
P 9150 2650
F 0 "K10" H 9150 2650 60  0000 C CNN
F 1 "KEYSW" H 9150 2550 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 9150 2650 60  0001 C CNN
F 3 "" H 9150 2650 60  0000 C CNN
	1    9150 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 2650 8850 2650
Wire Wire Line
	9550 3250 9550 3150
Wire Wire Line
	8750 3250 9550 3250
Wire Wire Line
	7950 3250 8750 3250
Wire Wire Line
	8750 3250 8750 3150
$Comp
L KeyboardParts:D D10
U 1 1 5EB2CA29
P 8750 3100
F 0 "D10" H 8622 3050 60  0000 R CNN
F 1 "D" V 8900 3050 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 8750 3100 60  0001 C CNN
F 3 "" H 8750 3100 60  0000 C CNN
	1    8750 3100
	-1   0    0    1   
$EndComp
Connection ~ 8750 3250
$Comp
L KeyboardParts:KEYSW K11
U 1 1 5EB2CA30
P 9950 2650
F 0 "K11" H 9950 2650 60  0000 C CNN
F 1 "KEYSW" H 9950 2550 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 9950 2650 60  0001 C CNN
F 3 "" H 9950 2650 60  0000 C CNN
	1    9950 2650
	1    0    0    -1  
$EndComp
$Comp
L KeyboardParts:D D11
U 1 1 5EB2CA36
P 9550 3100
F 0 "D11" H 9422 3050 60  0000 R CNN
F 1 "D" V 9700 3050 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 9550 3100 60  0001 C CNN
F 3 "" H 9550 3100 60  0000 C CNN
	1    9550 3100
	-1   0    0    1   
$EndComp
Wire Wire Line
	9550 2650 9650 2650
$Comp
L KeyboardParts:KEYSW K12
U 1 1 5EB2CA3F
P 10750 2650
F 0 "K12" H 10750 2650 60  0000 C CNN
F 1 "KEYSW" H 10750 2550 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 10750 2650 60  0001 C CNN
F 3 "" H 10750 2650 60  0000 C CNN
	1    10750 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 2650 10450 2650
Wire Wire Line
	9550 3250 10350 3250
Wire Wire Line
	10350 3250 10350 3150
$Comp
L KeyboardParts:D D12
U 1 1 5EB2CA4A
P 10350 3100
F 0 "D12" H 10222 3050 60  0000 R CNN
F 1 "D" V 10500 3050 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 10350 3100 60  0001 C CNN
F 3 "" H 10350 3100 60  0000 C CNN
	1    10350 3100
	-1   0    0    1   
$EndComp
$Comp
L KeyboardParts:KEYSW K13
U 1 1 5EB2CA50
P 8350 3450
F 0 "K13" H 8350 3450 60  0000 C CNN
F 1 "KEYSW" H 8350 3350 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 8350 3450 60  0001 C CNN
F 3 "" H 8350 3450 60  0000 C CNN
	1    8350 3450
	1    0    0    -1  
$EndComp
$Comp
L KeyboardParts:D D13
U 1 1 5EB2CA56
P 7950 3700
F 0 "D13" H 7822 3650 60  0000 R CNN
F 1 "D" V 8100 3650 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 7950 3700 60  0001 C CNN
F 3 "" H 7950 3700 60  0000 C CNN
	1    7950 3700
	-1   0    0    1   
$EndComp
Wire Wire Line
	7950 3550 7950 3450
Wire Wire Line
	7950 3450 8050 3450
Wire Wire Line
	7950 3750 7950 3850
$Comp
L KeyboardParts:KEYSW K14
U 1 1 5EB2CA5F
P 9150 3450
F 0 "K14" H 9150 3450 60  0000 C CNN
F 1 "KEYSW" H 9150 3350 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 9150 3450 60  0001 C CNN
F 3 "" H 9150 3450 60  0000 C CNN
	1    9150 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 3550 8750 3450
Wire Wire Line
	8750 3450 8850 3450
Wire Wire Line
	9550 3850 9550 3750
Wire Wire Line
	8750 3850 9550 3850
Wire Wire Line
	8750 3850 8750 3750
$Comp
L KeyboardParts:KEYSW K15
U 1 1 5EB2CA72
P 9950 3450
F 0 "K15" H 9950 3450 60  0000 C CNN
F 1 "KEYSW" H 9950 3350 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 9950 3450 60  0001 C CNN
F 3 "" H 9950 3450 60  0000 C CNN
	1    9950 3450
	1    0    0    -1  
$EndComp
$Comp
L KeyboardParts:D D15
U 1 1 5EB2CA78
P 9550 3700
F 0 "D15" H 9422 3650 60  0000 R CNN
F 1 "D" V 9700 3650 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 9550 3700 60  0001 C CNN
F 3 "" H 9550 3700 60  0000 C CNN
	1    9550 3700
	-1   0    0    1   
$EndComp
Wire Wire Line
	9550 3550 9550 3450
Wire Wire Line
	9550 3450 9650 3450
$Comp
L KeyboardParts:KEYSW K16
U 1 1 5EB2CA80
P 10750 3450
F 0 "K16" H 10750 3450 60  0000 C CNN
F 1 "KEYSW" H 10750 3350 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 10750 3450 60  0001 C CNN
F 3 "" H 10750 3450 60  0000 C CNN
	1    10750 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 3550 10350 3450
Wire Wire Line
	10350 3450 10450 3450
Wire Wire Line
	9550 3850 10350 3850
Wire Wire Line
	10350 3850 10350 3750
$Comp
L KeyboardParts:D D16
U 1 1 5EB2CA8A
P 10350 3700
F 0 "D16" H 10222 3650 60  0000 R CNN
F 1 "D" V 10500 3650 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 10350 3700 60  0001 C CNN
F 3 "" H 10350 3700 60  0000 C CNN
	1    10350 3700
	-1   0    0    1   
$EndComp
Wire Wire Line
	7950 3250 7850 3250
Connection ~ 7950 3250
Wire Wire Line
	7950 3850 7850 3850
Wire Wire Line
	6850 2950 6800 2950
Wire Wire Line
	8650 2050 8650 2650
Connection ~ 8650 2050
Wire Wire Line
	9550 2050 9650 2050
Wire Wire Line
	9450 2050 9450 2650
Connection ~ 9450 2050
Wire Wire Line
	10250 2050 10250 2650
Connection ~ 10250 2050
Wire Wire Line
	11050 2050 11050 2650
Connection ~ 11050 2050
$Comp
L KeyboardParts:D D17
U 1 1 5EB8034D
P 7950 4500
F 0 "D17" H 7822 4450 60  0000 R CNN
F 1 "D" V 8100 4450 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 7950 4500 60  0001 C CNN
F 3 "" H 7950 4500 60  0000 C CNN
	1    7950 4500
	-1   0    0    1   
$EndComp
Wire Wire Line
	7950 4050 8050 4050
Wire Wire Line
	7950 4550 7950 4650
$Comp
L KeyboardParts:KEYSW K18
U 1 1 5EB80356
P 9150 4050
F 0 "K18" H 9150 4050 60  0000 C CNN
F 1 "KEYSW" H 9150 3950 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 9150 4050 60  0001 C CNN
F 3 "" H 9150 4050 60  0000 C CNN
	1    9150 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 4050 8850 4050
Wire Wire Line
	9550 4650 9550 4550
Wire Wire Line
	8750 4650 9550 4650
Wire Wire Line
	7950 4650 8750 4650
Wire Wire Line
	8750 4650 8750 4550
$Comp
L KeyboardParts:D D18
U 1 1 5EB80362
P 8750 4500
F 0 "D18" H 8622 4450 60  0000 R CNN
F 1 "D" V 8900 4450 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 8750 4500 60  0001 C CNN
F 3 "" H 8750 4500 60  0000 C CNN
	1    8750 4500
	-1   0    0    1   
$EndComp
Connection ~ 8750 4650
$Comp
L KeyboardParts:KEYSW K19
U 1 1 5EB80369
P 9950 4050
F 0 "K19" H 9950 4050 60  0000 C CNN
F 1 "KEYSW" H 9950 3950 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 9950 4050 60  0001 C CNN
F 3 "" H 9950 4050 60  0000 C CNN
	1    9950 4050
	1    0    0    -1  
$EndComp
$Comp
L KeyboardParts:D D19
U 1 1 5EB8036F
P 9550 4500
F 0 "D19" H 9422 4450 60  0000 R CNN
F 1 "D" V 9700 4450 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 9550 4500 60  0001 C CNN
F 3 "" H 9550 4500 60  0000 C CNN
	1    9550 4500
	-1   0    0    1   
$EndComp
Wire Wire Line
	9550 4050 9650 4050
$Comp
L KeyboardParts:KEYSW K20
U 1 1 5EB80377
P 10750 4050
F 0 "K20" H 10750 4050 60  0000 C CNN
F 1 "KEYSW" H 10750 3950 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 10750 4050 60  0001 C CNN
F 3 "" H 10750 4050 60  0000 C CNN
	1    10750 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 4050 10450 4050
Wire Wire Line
	9550 4650 10350 4650
Wire Wire Line
	10350 4650 10350 4550
$Comp
L KeyboardParts:D D20
U 1 1 5EB80381
P 10350 4500
F 0 "D20" H 10222 4450 60  0000 R CNN
F 1 "D" V 10500 4450 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 10350 4500 60  0001 C CNN
F 3 "" H 10350 4500 60  0000 C CNN
	1    10350 4500
	-1   0    0    1   
$EndComp
Wire Wire Line
	7950 4650 7850 4650
Connection ~ 7950 4650
Connection ~ 7950 3850
Connection ~ 8750 3850
$Comp
L KeyboardParts:KEYSW K17
U 1 1 5EB80347
P 8350 4050
F 0 "K17" H 8350 4050 60  0000 C CNN
F 1 "KEYSW" H 8350 3950 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_Plate" H 8350 4050 60  0001 C CNN
F 3 "" H 8350 4050 60  0000 C CNN
	1    8350 4050
	1    0    0    -1  
$EndComp
$Comp
L KeyboardParts:D D14
U 1 1 5EB2CA6B
P 8750 3700
F 0 "D14" H 8622 3650 60  0000 R CNN
F 1 "D" V 8900 3650 60  0001 C CNN
F 2 "KeyboardPartsPretty:D_SOD123_axial" H 8750 3700 60  0001 C CNN
F 3 "" H 8750 3700 60  0000 C CNN
	1    8750 3700
	-1   0    0    1   
$EndComp
Wire Wire Line
	7950 3850 8750 3850
Wire Wire Line
	8650 4050 8650 3450
Connection ~ 8650 3450
Wire Wire Line
	9450 4050 9450 3450
Connection ~ 9450 3450
Wire Wire Line
	10250 4050 10250 3450
Connection ~ 10250 3450
Wire Wire Line
	11050 4050 11050 3450
Connection ~ 11050 3450
Connection ~ 9550 1850
Connection ~ 9550 2450
Connection ~ 9550 3250
Connection ~ 9550 3850
Connection ~ 9550 4650
Text GLabel 7850 1850 0    50   Input ~ 0
row0
Text GLabel 7850 2450 0    50   Input ~ 0
row1
Text GLabel 7850 3250 0    50   Input ~ 0
row2
Text GLabel 7850 3850 0    50   Input ~ 0
row3
Text GLabel 7850 4650 0    50   Input ~ 0
row4
Text GLabel 8650 1300 1    50   Input ~ 0
col0
Text GLabel 9450 1300 1    50   Input ~ 0
col1
Text GLabel 10250 1300 1    50   Input ~ 0
col2
Text GLabel 11050 1300 1    50   Input ~ 0
col3
Text GLabel 6800 3550 2    50   Input ~ 0
row4
Text GLabel 6800 3450 2    50   Input ~ 0
row3
Text GLabel 6800 3350 2    50   Input ~ 0
row2
Text GLabel 6800 3250 2    50   Input ~ 0
row1
Text GLabel 6800 3150 2    50   Input ~ 0
row0
Text GLabel 6800 2250 2    50   Input ~ 0
col0
Text GLabel 6800 2350 2    50   Input ~ 0
col1
Text GLabel 6800 2450 2    50   Input ~ 0
col2
Text GLabel 6800 2550 2    50   Input ~ 0
col3
$Comp
L power:VCC #PWR0119
U 1 1 5EC378ED
P 2150 7350
F 0 "#PWR0119" H 2150 7200 50  0001 C CNN
F 1 "VCC" V 2167 7478 50  0000 L CNN
F 2 "" H 2150 7350 50  0001 C CNN
F 3 "" H 2150 7350 50  0001 C CNN
	1    2150 7350
	0    1    1    0   
$EndComp
Wire Wire Line
	2150 7350 2050 7350
Text GLabel 2050 7550 2    50   Input ~ 0
enSw
Text GLabel 1450 7350 0    50   Input ~ 0
enA
Text GLabel 1450 7550 0    50   Input ~ 0
enB
Text GLabel 4650 3550 0    50   Input ~ 0
SCL
Text GLabel 4650 3650 0    50   Input ~ 0
SDA
$Comp
L power:VCC #PWR0120
U 1 1 5EC43493
P 4500 1950
F 0 "#PWR0120" H 4500 1800 50  0001 C CNN
F 1 "VCC" V 4518 2077 50  0000 L CNN
F 2 "" H 4500 1950 50  0001 C CNN
F 3 "" H 4500 1950 50  0001 C CNN
	1    4500 1950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4500 1950 4650 1950
Text GLabel 6800 2650 2    50   Input ~ 0
enSw
Text GLabel 6800 3650 2    50   Input ~ 0
enA
Text GLabel 6800 3750 2    50   Input ~ 0
enB
$Comp
L Device:Rotary_Encoder_Switch SW2
U 1 1 5EABA61B
P 1750 7450
F 0 "SW2" H 1750 7817 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 1750 7726 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC12E-Switch_Vertical_H20mm" H 1600 7610 50  0001 C CNN
F 3 "~" H 1750 7710 50  0001 C CNN
	1    1750 7450
	1    0    0    -1  
$EndComp
Text GLabel 4650 2950 0    50   Input ~ 0
RGB
NoConn ~ 4650 3950
NoConn ~ 4650 3850
NoConn ~ 4650 3750
NoConn ~ 4650 2850
NoConn ~ 4650 2750
NoConn ~ 4650 2650
NoConn ~ 4650 2550
NoConn ~ 4650 1850
NoConn ~ 6800 2050
$Comp
L power:GND #PWR0101
U 1 1 5EB1970D
P 2850 2950
F 0 "#PWR0101" H 2850 2700 50  0001 C CNN
F 1 "GND" V 2855 2822 50  0000 R CNN
F 2 "" H 2850 2950 50  0001 C CNN
F 3 "" H 2850 2950 50  0001 C CNN
	1    2850 2950
	0    1    1    0   
$EndComp
Wire Wire Line
	2850 2950 2950 2950
Connection ~ 2950 2950
$Comp
L power:GND #PWR0103
U 1 1 5EB825C7
P 4500 3250
F 0 "#PWR0103" H 4500 3000 50  0001 C CNN
F 1 "GND" V 4505 3122 50  0000 R CNN
F 2 "" H 4500 3250 50  0001 C CNN
F 3 "" H 4500 3250 50  0001 C CNN
	1    4500 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 3250 4650 3250
$Comp
L power:GND #PWR0105
U 1 1 5EBA500C
P 4200 2250
F 0 "#PWR0105" H 4200 2000 50  0001 C CNN
F 1 "GND" V 4205 2122 50  0000 R CNN
F 2 "" H 4200 2250 50  0001 C CNN
F 3 "" H 4200 2250 50  0001 C CNN
	1    4200 2250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5EBB0C3F
P 2600 1700
F 0 "#PWR0107" H 2600 1450 50  0001 C CNN
F 1 "GND" V 2605 1572 50  0000 R CNN
F 2 "" H 2600 1700 50  0001 C CNN
F 3 "" H 2600 1700 50  0001 C CNN
	1    2600 1700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2500 1700 2600 1700
Wire Wire Line
	2500 1800 2500 1700
Connection ~ 2500 1700
Wire Wire Line
	3200 4200 3200 4100
$Comp
L power:GND #PWR0130
U 1 1 5EC8CDDA
P 1250 7450
F 0 "#PWR0130" H 1250 7200 50  0001 C CNN
F 1 "GND" V 1255 7322 50  0000 R CNN
F 2 "" H 1250 7450 50  0001 C CNN
F 3 "" H 1250 7450 50  0001 C CNN
	1    1250 7450
	0    1    1    0   
$EndComp
Wire Wire Line
	1250 7450 1450 7450
$Comp
L power:GND #PWR0132
U 1 1 5ECA3E79
P 7000 3950
F 0 "#PWR0132" H 7000 3700 50  0001 C CNN
F 1 "GND" V 7005 3822 50  0000 R CNN
F 2 "" H 7000 3950 50  0001 C CNN
F 3 "" H 7000 3950 50  0001 C CNN
	1    7000 3950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7000 3950 6800 3950
$Comp
L power:GND #PWR0134
U 1 1 5ECC72CF
P 7000 2750
F 0 "#PWR0134" H 7000 2500 50  0001 C CNN
F 1 "GND" V 7005 2622 50  0000 R CNN
F 2 "" H 7000 2750 50  0001 C CNN
F 3 "" H 7000 2750 50  0001 C CNN
	1    7000 2750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7000 2750 6800 2750
$Comp
L power:GND #PWR0136
U 1 1 5ECDE5FA
P 7000 1950
F 0 "#PWR0136" H 7000 1700 50  0001 C CNN
F 1 "GND" V 7005 1822 50  0000 R CNN
F 2 "" H 7000 1950 50  0001 C CNN
F 3 "" H 7000 1950 50  0001 C CNN
	1    7000 1950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6800 1950 7000 1950
$Comp
L power:GND #PWR0138
U 1 1 5ECF5839
P 5000 1400
F 0 "#PWR0138" H 5000 1150 50  0001 C CNN
F 1 "GND" H 5005 1227 50  0000 C CNN
F 2 "" H 5000 1400 50  0001 C CNN
F 3 "" H 5000 1400 50  0001 C CNN
	1    5000 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 1400 5000 1300
Connection ~ 5000 1300
$Comp
L power:GND #PWR0106
U 1 1 5ED83062
P 7400 2950
F 0 "#PWR0106" H 7400 2700 50  0001 C CNN
F 1 "GND" V 7405 2822 50  0000 R CNN
F 2 "" H 7400 2950 50  0001 C CNN
F 3 "" H 7400 2950 50  0001 C CNN
	1    7400 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7400 2950 7350 2950
$Comp
L Connector_Generic:Conn_01x04 L31
U 1 1 5EB57670
P 3500 7400
F 0 "L31" H 3580 7392 50  0000 L CNN
F 1 ".91\" OLED" H 3580 7301 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 3500 7400 50  0001 C CNN
F 3 "~" H 3500 7400 50  0001 C CNN
	1    3500 7400
	1    0    0    -1  
$EndComp
Text GLabel 3300 7300 0    50   Input ~ 0
SDA
Text GLabel 3300 7400 0    50   Input ~ 0
SCL
$Comp
L power:VCC #PWR0140
U 1 1 5EB5A8FB
P 3100 7500
F 0 "#PWR0140" H 3100 7350 50  0001 C CNN
F 1 "VCC" V 3118 7627 50  0000 L CNN
F 2 "" H 3100 7500 50  0001 C CNN
F 3 "" H 3100 7500 50  0001 C CNN
	1    3100 7500
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0141
U 1 1 5EB5D0C2
P 3100 7600
F 0 "#PWR0141" H 3100 7350 50  0001 C CNN
F 1 "GND" V 3105 7472 50  0000 R CNN
F 2 "" H 3100 7600 50  0001 C CNN
F 3 "" H 3100 7600 50  0001 C CNN
	1    3100 7600
	0    1    1    0   
$EndComp
Wire Wire Line
	3100 7600 3300 7600
Wire Wire Line
	3100 7500 3300 7500
$Comp
L KeyboardParts:KEYSW K17B1
U 1 1 5EBBDDB6
P 8350 4250
F 0 "K17B1" H 8350 4250 60  0000 C CNN
F 1 "KEYSW" H 8350 4150 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_2.00u_Plate" H 8350 4250 60  0001 C CNN
F 3 "" H 8350 4250 60  0000 C CNN
	1    8350 4250
	1    0    0    -1  
$EndComp
$Comp
L KeyboardParts:KEYSW K20B1
U 1 1 5EBBEA83
P 10750 4250
F 0 "K20B1" H 10750 4250 60  0000 C CNN
F 1 "KEYSW" H 10750 4150 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_2.00u_Vertical_Plate" H 10750 4250 60  0001 C CNN
F 3 "" H 10750 4250 60  0000 C CNN
	1    10750 4250
	-1   0    0    1   
$EndComp
Wire Wire Line
	7950 2650 7950 2950
Wire Wire Line
	8650 2650 8650 3450
Connection ~ 8650 2650
Wire Wire Line
	8750 2650 8750 2950
Wire Wire Line
	9450 2650 9450 3450
Connection ~ 9450 2650
Wire Wire Line
	9550 2650 9550 2950
Wire Wire Line
	10250 2650 10250 3450
Connection ~ 10250 2650
Wire Wire Line
	10350 2650 10350 2850
Wire Wire Line
	10450 2850 10350 2850
Connection ~ 10350 2850
Wire Wire Line
	10350 2850 10350 2950
Connection ~ 11050 2650
Wire Wire Line
	7950 4050 7950 4250
Wire Wire Line
	8650 4250 8650 4050
Connection ~ 8650 4050
Wire Wire Line
	8050 4250 7950 4250
Connection ~ 7950 4250
Wire Wire Line
	7950 4250 7950 4350
Wire Wire Line
	8750 4050 8750 4350
Wire Wire Line
	9550 4050 9550 4350
Wire Wire Line
	11050 4050 11050 4250
Connection ~ 11050 4050
Wire Wire Line
	10450 4250 10350 4250
Wire Wire Line
	10350 4050 10350 4250
Wire Wire Line
	10350 4250 10350 4350
Connection ~ 10350 4250
$Comp
L power:VCC #PWR0121
U 1 1 5EC5DD91
P 1100 4850
F 0 "#PWR0121" H 1100 4700 50  0001 C CNN
F 1 "VCC" H 1117 5023 50  0000 C CNN
F 2 "" H 1100 4850 50  0001 C CNN
F 3 "" H 1100 4850 50  0001 C CNN
	1    1100 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 4900 1100 4850
Wire Wire Line
	1400 5200 1450 5200
$Comp
L power:VCC #PWR0123
U 1 1 5EC99D45
P 1750 4850
F 0 "#PWR0123" H 1750 4700 50  0001 C CNN
F 1 "VCC" H 1767 5023 50  0000 C CNN
F 2 "" H 1750 4850 50  0001 C CNN
F 3 "" H 1750 4850 50  0001 C CNN
	1    1750 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 4900 1750 4850
$Comp
L LED:WS2812B L22
U 1 1 5EC99D52
P 1750 5200
F 0 "L22" H 1800 5450 50  0000 L CNN
F 1 "WS2812B" H 1800 4950 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 1800 4900 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 1850 4825 50  0001 L TNN
	1    1750 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 5200 2100 5200
$Comp
L power:VCC #PWR0125
U 1 1 5ECA36F0
P 2400 4850
F 0 "#PWR0125" H 2400 4700 50  0001 C CNN
F 1 "VCC" H 2417 5023 50  0000 C CNN
F 2 "" H 2400 4850 50  0001 C CNN
F 3 "" H 2400 4850 50  0001 C CNN
	1    2400 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 4900 2400 4850
$Comp
L LED:WS2812B L23
U 1 1 5ECA36FD
P 2400 5200
F 0 "L23" H 2450 5450 50  0000 L CNN
F 1 "WS2812B" H 2450 4950 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 2450 4900 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 2500 4825 50  0001 L TNN
	1    2400 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 5200 2750 5200
$Comp
L power:VCC #PWR0127
U 1 1 5ECAD00B
P 3050 4850
F 0 "#PWR0127" H 3050 4700 50  0001 C CNN
F 1 "VCC" H 3067 5023 50  0000 C CNN
F 2 "" H 3050 4850 50  0001 C CNN
F 3 "" H 3050 4850 50  0001 C CNN
	1    3050 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 4900 3050 4850
$Comp
L LED:WS2812B L24
U 1 1 5ECAD018
P 3050 5200
F 0 "L24" H 3100 5450 50  0000 L CNN
F 1 "WS2812B" H 3100 4950 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 3100 4900 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 3150 4825 50  0001 L TNN
	1    3050 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 5200 3400 5200
$Comp
L power:VCC #PWR0129
U 1 1 5ECB6DCB
P 3700 4850
F 0 "#PWR0129" H 3700 4700 50  0001 C CNN
F 1 "VCC" H 3717 5023 50  0000 C CNN
F 2 "" H 3700 4850 50  0001 C CNN
F 3 "" H 3700 4850 50  0001 C CNN
	1    3700 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 4900 3700 4850
$Comp
L LED:WS2812B L25
U 1 1 5ECB6DD8
P 3700 5200
F 0 "L25" H 3750 5450 50  0000 L CNN
F 1 "WS2812B" H 3750 4950 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 3750 4900 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 3800 4825 50  0001 L TNN
	1    3700 5200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0131
U 1 1 5ECC0D5D
P 3700 6700
F 0 "#PWR0131" H 3700 6550 50  0001 C CNN
F 1 "VCC" H 3717 6873 50  0000 C CNN
F 2 "" H 3700 6700 50  0001 C CNN
F 3 "" H 3700 6700 50  0001 C CNN
	1    3700 6700
	-1   0    0    1   
$EndComp
Wire Wire Line
	3700 6650 3700 6700
$Comp
L LED:WS2812B L26
U 1 1 5ECC0D6A
P 3700 6350
F 0 "L26" H 3750 6600 50  0000 L CNN
F 1 "WS2812B" H 3750 6100 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 3750 6050 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 3800 5975 50  0001 L TNN
	1    3700 6350
	-1   0    0    1   
$EndComp
Wire Wire Line
	3400 6350 3350 6350
$Comp
L power:VCC #PWR0133
U 1 1 5ECCB038
P 3050 6700
F 0 "#PWR0133" H 3050 6550 50  0001 C CNN
F 1 "VCC" H 3067 6873 50  0000 C CNN
F 2 "" H 3050 6700 50  0001 C CNN
F 3 "" H 3050 6700 50  0001 C CNN
	1    3050 6700
	-1   0    0    1   
$EndComp
Wire Wire Line
	3050 6650 3050 6700
$Comp
L LED:WS2812B L27
U 1 1 5ECCB045
P 3050 6350
F 0 "L27" H 3100 6600 50  0000 L CNN
F 1 "WS2812B" H 3100 6100 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 3100 6050 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 3150 5975 50  0001 L TNN
	1    3050 6350
	-1   0    0    1   
$EndComp
Wire Wire Line
	2750 6350 2700 6350
$Comp
L power:VCC #PWR0135
U 1 1 5ECD5505
P 2400 6700
F 0 "#PWR0135" H 2400 6550 50  0001 C CNN
F 1 "VCC" H 2417 6873 50  0000 C CNN
F 2 "" H 2400 6700 50  0001 C CNN
F 3 "" H 2400 6700 50  0001 C CNN
	1    2400 6700
	-1   0    0    1   
$EndComp
Wire Wire Line
	2400 6650 2400 6700
$Comp
L LED:WS2812B L28
U 1 1 5ECD5512
P 2400 6350
F 0 "L28" H 2450 6600 50  0000 L CNN
F 1 "WS2812B" H 2450 6100 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 2450 6050 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 2500 5975 50  0001 L TNN
	1    2400 6350
	-1   0    0    1   
$EndComp
Wire Wire Line
	2100 6350 2050 6350
$Comp
L power:VCC #PWR0137
U 1 1 5ECE1107
P 1750 6700
F 0 "#PWR0137" H 1750 6550 50  0001 C CNN
F 1 "VCC" H 1767 6873 50  0000 C CNN
F 2 "" H 1750 6700 50  0001 C CNN
F 3 "" H 1750 6700 50  0001 C CNN
	1    1750 6700
	-1   0    0    1   
$EndComp
Wire Wire Line
	1750 6650 1750 6700
$Comp
L LED:WS2812B L29
U 1 1 5ECE1114
P 1750 6350
F 0 "L29" H 1800 6600 50  0000 L CNN
F 1 "WS2812B" H 1800 6100 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 1800 6050 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 1850 5975 50  0001 L TNN
	1    1750 6350
	-1   0    0    1   
$EndComp
Wire Wire Line
	1450 6350 1400 6350
$Comp
L power:VCC #PWR0139
U 1 1 5ECEC1EA
P 1100 6700
F 0 "#PWR0139" H 1100 6550 50  0001 C CNN
F 1 "VCC" H 1117 6873 50  0000 C CNN
F 2 "" H 1100 6700 50  0001 C CNN
F 3 "" H 1100 6700 50  0001 C CNN
	1    1100 6700
	-1   0    0    1   
$EndComp
Wire Wire Line
	1100 6650 1100 6700
$Comp
L LED:WS2812B L30
U 1 1 5ECEC1F7
P 1100 6350
F 0 "L30" H 1150 6600 50  0000 L CNN
F 1 "WS2812B" H 1150 6100 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 1150 6050 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 1200 5975 50  0001 L TNN
	1    1100 6350
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5EBEAD88
P 3200 4200
F 0 "#PWR0108" H 3200 3950 50  0001 C CNN
F 1 "GND" H 3205 4027 50  0000 C CNN
F 2 "" H 3200 4200 50  0001 C CNN
F 3 "" H 3200 4200 50  0001 C CNN
	1    3200 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 5550 1100 5500
$Comp
L power:GND #PWR0109
U 1 1 5EBF72D2
P 1100 5550
F 0 "#PWR0109" H 1100 5300 50  0001 C CNN
F 1 "GND" H 1105 5377 50  0000 C CNN
F 2 "" H 1100 5550 50  0001 C CNN
F 3 "" H 1100 5550 50  0001 C CNN
	1    1100 5550
	1    0    0    -1  
$EndComp
$Comp
L LED:WS2812B L21
U 1 1 5EC4DD94
P 1100 5200
F 0 "L21" H 1150 5450 50  0000 L CNN
F 1 "WS2812B" H 1150 4950 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 1150 4900 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 1200 4825 50  0001 L TNN
	1    1100 5200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5EC191A4
P 1750 5550
F 0 "#PWR0114" H 1750 5300 50  0001 C CNN
F 1 "GND" H 1755 5377 50  0000 C CNN
F 2 "" H 1750 5550 50  0001 C CNN
F 3 "" H 1750 5550 50  0001 C CNN
	1    1750 5550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 5EC19753
P 2400 5550
F 0 "#PWR0115" H 2400 5300 50  0001 C CNN
F 1 "GND" H 2405 5377 50  0000 C CNN
F 2 "" H 2400 5550 50  0001 C CNN
F 3 "" H 2400 5550 50  0001 C CNN
	1    2400 5550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5EC19B84
P 3050 5550
F 0 "#PWR0116" H 3050 5300 50  0001 C CNN
F 1 "GND" H 3055 5377 50  0000 C CNN
F 2 "" H 3050 5550 50  0001 C CNN
F 3 "" H 3050 5550 50  0001 C CNN
	1    3050 5550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 5EC19FC3
P 3700 5550
F 0 "#PWR0117" H 3700 5300 50  0001 C CNN
F 1 "GND" H 3705 5377 50  0000 C CNN
F 2 "" H 3700 5550 50  0001 C CNN
F 3 "" H 3700 5550 50  0001 C CNN
	1    3700 5550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0118
U 1 1 5EC1A4F4
P 3700 6000
F 0 "#PWR0118" H 3700 5750 50  0001 C CNN
F 1 "GND" H 3705 5827 50  0000 C CNN
F 2 "" H 3700 6000 50  0001 C CNN
F 3 "" H 3700 6000 50  0001 C CNN
	1    3700 6000
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0122
U 1 1 5EC1AA16
P 3050 6000
F 0 "#PWR0122" H 3050 5750 50  0001 C CNN
F 1 "GND" H 3055 5827 50  0000 C CNN
F 2 "" H 3050 6000 50  0001 C CNN
F 3 "" H 3050 6000 50  0001 C CNN
	1    3050 6000
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0124
U 1 1 5EC1AE76
P 2400 6000
F 0 "#PWR0124" H 2400 5750 50  0001 C CNN
F 1 "GND" H 2405 5827 50  0000 C CNN
F 2 "" H 2400 6000 50  0001 C CNN
F 3 "" H 2400 6000 50  0001 C CNN
	1    2400 6000
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0126
U 1 1 5EC1B2B9
P 1750 6000
F 0 "#PWR0126" H 1750 5750 50  0001 C CNN
F 1 "GND" H 1755 5827 50  0000 C CNN
F 2 "" H 1750 6000 50  0001 C CNN
F 3 "" H 1750 6000 50  0001 C CNN
	1    1750 6000
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0128
U 1 1 5EC1B6D3
P 1100 6000
F 0 "#PWR0128" H 1100 5750 50  0001 C CNN
F 1 "GND" H 1105 5827 50  0000 C CNN
F 2 "" H 1100 6000 50  0001 C CNN
F 3 "" H 1100 6000 50  0001 C CNN
	1    1100 6000
	-1   0    0    1   
$EndComp
Wire Wire Line
	1750 5550 1750 5500
Wire Wire Line
	2400 5550 2400 5500
Wire Wire Line
	3050 5550 3050 5500
Wire Wire Line
	3700 6000 3700 6050
Wire Wire Line
	3050 6000 3050 6050
Wire Wire Line
	2400 6000 2400 6050
Wire Wire Line
	1750 6000 1750 6050
Wire Wire Line
	1100 6000 1100 6050
Text GLabel 700  4550 1    50   Input ~ 0
RGB
Wire Wire Line
	700  5200 800  5200
Wire Wire Line
	1000 4100 1300 4100
Connection ~ 1300 4100
$Comp
L KeyboardParts:LED L1
U 1 1 5ED14269
P 4350 5350
F 0 "L1" V 4450 5350 50  0000 R CNN
F 1 "1.8mm" V 4150 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 4350 5350 60  0001 C CNN
F 3 "" H 4350 5350 60  0000 C CNN
	1    4350 5350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4150 5200 4150 6350
Wire Wire Line
	4150 6350 4000 6350
Wire Wire Line
	4000 5200 4150 5200
Text Notes 4650 5100 0    50   ~ 0
(5V-3V) / 330 = 6 mA\nMax current is 20 mA
Wire Wire Line
	700  4700 700  4550
$Comp
L KeyboardParts:R R7
U 1 1 5EC54AE4
P 700 4950
F 0 "R7" V 700 5050 50  0000 C CNN
F 1 "500" V 700 4900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 700 4950 60  0001 C CNN
F 3 "" H 700 4950 60  0000 C CNN
	1    700  4950
	1    0    0    -1  
$EndComp
$Comp
L KeyboardParts:R R10
U 1 1 5EE2F609
P 4350 5850
F 0 "R10" V 4350 5750 50  0000 C CNN
F 1 "330" V 4350 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4350 5850 60  0001 C CNN
F 3 "" H 4350 5850 60  0000 C CNN
	1    4350 5850
	-1   0    0    1   
$EndComp
$Comp
L JCLPCB-MOSFET:AO3400 U2
U 1 1 5EE5F228
P 6350 6750
F 0 "U2" H 6494 6746 50  0000 L CNN
F 1 "AO3400" H 6494 6655 50  0000 L CNN
F 2 "JLCPCB-MOSFET:SOT23" H 6350 6750 50  0001 L BNN
F 3 "Unavailable" H 6350 6750 50  0001 L BNN
F 4 "None" H 6350 6750 50  0001 L BNN "Field4"
F 5 "N-Channel 30V 5.8A _Ta_ 1.4W _Ta_ Surface Mount SOT-23-3" H 6350 6750 50  0001 L BNN "Field5"
F 6 "Alpha &" H 6350 6750 50  0001 L BNN "Field6"
F 7 "SOT-23-3 Alpha &amp; Omega Semiconductor" H 6350 6750 50  0001 L BNN "Field7"
F 8 "AO3400" H 6350 6750 50  0001 L BNN "Field8"
	1    6350 6750
	1    0    0    -1  
$EndComp
Text Notes 6150 6800 0    50   ~ 0
G
Text Notes 6350 6550 0    50   ~ 0
D
Text Notes 6350 7000 0    50   ~ 0
S
$Comp
L KeyboardParts:R R9
U 1 1 5EE62972
P 5600 6850
F 0 "R9" V 5500 6850 50  0000 C CNN
F 1 "500" V 5600 6850 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5600 6850 60  0001 C CNN
F 3 "" H 5600 6850 60  0000 C CNN
	1    5600 6850
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0142
U 1 1 5EE63E8C
P 6450 7350
F 0 "#PWR0142" H 6450 7100 50  0001 C CNN
F 1 "GND" H 6455 7177 50  0000 C CNN
F 2 "" H 6450 7350 50  0001 C CNN
F 3 "" H 6450 7350 50  0001 C CNN
	1    6450 7350
	1    0    0    -1  
$EndComp
$Comp
L KeyboardParts:R R8
U 1 1 5EE65B08
P 6000 7100
F 0 "R8" V 5900 7100 50  0000 C CNN
F 1 "100k" V 6000 7100 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6000 7100 60  0001 C CNN
F 3 "" H 6000 7100 60  0000 C CNN
	1    6000 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 7350 6450 7350
Wire Wire Line
	6450 7050 6450 7350
Connection ~ 6450 7350
Wire Wire Line
	6000 6850 6150 6850
Wire Wire Line
	6000 6850 5850 6850
Connection ~ 6000 6850
Text GLabel 5200 6850 0    50   Input ~ 0
BKL
Wire Wire Line
	5200 6850 5350 6850
Wire Wire Line
	4350 5600 4350 5550
$Comp
L power:VCC #PWR0143
U 1 1 5EEF1BBA
P 4350 5000
F 0 "#PWR0143" H 4350 4850 50  0001 C CNN
F 1 "VCC" H 4367 5173 50  0000 C CNN
F 2 "" H 4350 5000 50  0001 C CNN
F 3 "" H 4350 5000 50  0001 C CNN
	1    4350 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 5150 4350 5000
$Comp
L KeyboardParts:LED L2
U 1 1 5EF061D2
P 4650 5350
F 0 "L2" V 4750 5350 50  0000 R CNN
F 1 "1.8mm" V 4450 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 4650 5350 60  0001 C CNN
F 3 "" H 4650 5350 60  0000 C CNN
	1    4650 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R11
U 1 1 5EF061D8
P 4650 5850
F 0 "R11" V 4650 5750 50  0000 C CNN
F 1 "330" V 4650 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4650 5850 60  0001 C CNN
F 3 "" H 4650 5850 60  0000 C CNN
	1    4650 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	4650 5600 4650 5550
$Comp
L KeyboardParts:LED L3
U 1 1 5EF1536D
P 4950 5350
F 0 "L3" V 5050 5350 50  0000 R CNN
F 1 "1.8mm" V 4750 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 4950 5350 60  0001 C CNN
F 3 "" H 4950 5350 60  0000 C CNN
	1    4950 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R12
U 1 1 5EF15373
P 4950 5850
F 0 "R12" V 4950 5750 50  0000 C CNN
F 1 "330" V 4950 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4950 5850 60  0001 C CNN
F 3 "" H 4950 5850 60  0000 C CNN
	1    4950 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	4950 5600 4950 5550
$Comp
L KeyboardParts:LED L4
U 1 1 5EF2415E
P 5250 5350
F 0 "L4" V 5350 5350 50  0000 R CNN
F 1 "1.8mm" V 5050 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 5250 5350 60  0001 C CNN
F 3 "" H 5250 5350 60  0000 C CNN
	1    5250 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R13
U 1 1 5EF24164
P 5250 5850
F 0 "R13" V 5250 5750 50  0000 C CNN
F 1 "330" V 5250 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5250 5850 60  0001 C CNN
F 3 "" H 5250 5850 60  0000 C CNN
	1    5250 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	5250 5600 5250 5550
$Comp
L KeyboardParts:LED L5
U 1 1 5EF33556
P 5550 5350
F 0 "L5" V 5650 5350 50  0000 R CNN
F 1 "1.8mm" V 5350 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 5550 5350 60  0001 C CNN
F 3 "" H 5550 5350 60  0000 C CNN
	1    5550 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R14
U 1 1 5EF3355C
P 5550 5850
F 0 "R14" V 5550 5750 50  0000 C CNN
F 1 "330" V 5550 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5550 5850 60  0001 C CNN
F 3 "" H 5550 5850 60  0000 C CNN
	1    5550 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	5550 5600 5550 5550
$Comp
L KeyboardParts:LED L6
U 1 1 5EF45FC0
P 5850 5350
F 0 "L6" V 5950 5350 50  0000 R CNN
F 1 "1.8mm" V 5650 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 5850 5350 60  0001 C CNN
F 3 "" H 5850 5350 60  0000 C CNN
	1    5850 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R15
U 1 1 5EF45FC6
P 5850 5850
F 0 "R15" V 5850 5750 50  0000 C CNN
F 1 "330" V 5850 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5850 5850 60  0001 C CNN
F 3 "" H 5850 5850 60  0000 C CNN
	1    5850 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	5850 5600 5850 5550
$Comp
L KeyboardParts:LED L7
U 1 1 5EF45FCD
P 6150 5350
F 0 "L7" V 6250 5350 50  0000 R CNN
F 1 "1.8mm" V 5950 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 6150 5350 60  0001 C CNN
F 3 "" H 6150 5350 60  0000 C CNN
	1    6150 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R16
U 1 1 5EF45FD3
P 6150 5850
F 0 "R16" V 6150 5750 50  0000 C CNN
F 1 "330" V 6150 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6150 5850 60  0001 C CNN
F 3 "" H 6150 5850 60  0000 C CNN
	1    6150 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	6150 5600 6150 5550
$Comp
L KeyboardParts:LED L8
U 1 1 5EF45FDA
P 6450 5350
F 0 "L8" V 6550 5350 50  0000 R CNN
F 1 "1.8mm" V 6250 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 6450 5350 60  0001 C CNN
F 3 "" H 6450 5350 60  0000 C CNN
	1    6450 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R17
U 1 1 5EF45FE0
P 6450 5850
F 0 "R17" V 6450 5750 50  0000 C CNN
F 1 "330" V 6450 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6450 5850 60  0001 C CNN
F 3 "" H 6450 5850 60  0000 C CNN
	1    6450 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	6450 5600 6450 5550
$Comp
L KeyboardParts:LED L9
U 1 1 5EF45FE7
P 7050 5350
F 0 "L9" V 7150 5350 50  0000 R CNN
F 1 "1.8mm" V 6850 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 7050 5350 60  0001 C CNN
F 3 "" H 7050 5350 60  0000 C CNN
	1    7050 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R18
U 1 1 5EF45FED
P 7050 5850
F 0 "R18" V 7050 5750 50  0000 C CNN
F 1 "330" V 7050 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7050 5850 60  0001 C CNN
F 3 "" H 7050 5850 60  0000 C CNN
	1    7050 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	7050 5600 7050 5550
$Comp
L KeyboardParts:LED L10
U 1 1 5EF45FF4
P 7350 5350
F 0 "L10" V 7450 5350 50  0000 R CNN
F 1 "1.8mm" V 7150 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 7350 5350 60  0001 C CNN
F 3 "" H 7350 5350 60  0000 C CNN
	1    7350 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R19
U 1 1 5EF45FFA
P 7350 5850
F 0 "R19" V 7350 5750 50  0000 C CNN
F 1 "330" V 7350 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7350 5850 60  0001 C CNN
F 3 "" H 7350 5850 60  0000 C CNN
	1    7350 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	7350 5600 7350 5550
$Comp
L KeyboardParts:LED L11
U 1 1 5EF592DE
P 7650 5350
F 0 "L11" V 7750 5350 50  0000 R CNN
F 1 "1.8mm" V 7450 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 7650 5350 60  0001 C CNN
F 3 "" H 7650 5350 60  0000 C CNN
	1    7650 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R20
U 1 1 5EF592E4
P 7650 5850
F 0 "R20" V 7650 5750 50  0000 C CNN
F 1 "330" V 7650 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7650 5850 60  0001 C CNN
F 3 "" H 7650 5850 60  0000 C CNN
	1    7650 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	7650 5600 7650 5550
$Comp
L KeyboardParts:LED L12
U 1 1 5EF592EB
P 7950 5350
F 0 "L12" V 8050 5350 50  0000 R CNN
F 1 "1.8mm" V 7750 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 7950 5350 60  0001 C CNN
F 3 "" H 7950 5350 60  0000 C CNN
	1    7950 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R21
U 1 1 5EF592F1
P 7950 5850
F 0 "R21" V 7950 5750 50  0000 C CNN
F 1 "330" V 7950 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7950 5850 60  0001 C CNN
F 3 "" H 7950 5850 60  0000 C CNN
	1    7950 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	7950 5600 7950 5550
$Comp
L KeyboardParts:LED L8B1
U 1 1 5EF592F8
P 6750 5350
F 0 "L8B1" V 6850 5350 50  0000 R CNN
F 1 "1.8mm" V 6550 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 6750 5350 60  0001 C CNN
F 3 "" H 6750 5350 60  0000 C CNN
	1    6750 5350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6750 5600 6750 5550
$Comp
L KeyboardParts:LED L13
U 1 1 5EF59305
P 8250 5350
F 0 "L13" V 8350 5350 50  0000 R CNN
F 1 "1.8mm" V 8050 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 8250 5350 60  0001 C CNN
F 3 "" H 8250 5350 60  0000 C CNN
	1    8250 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R22
U 1 1 5EF5930B
P 8250 5850
F 0 "R22" V 8250 5750 50  0000 C CNN
F 1 "330" V 8250 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8250 5850 60  0001 C CNN
F 3 "" H 8250 5850 60  0000 C CNN
	1    8250 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	8250 5600 8250 5550
$Comp
L KeyboardParts:LED L14
U 1 1 5EF59312
P 8550 5350
F 0 "L14" V 8650 5350 50  0000 R CNN
F 1 "1.8mm" V 8350 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 8550 5350 60  0001 C CNN
F 3 "" H 8550 5350 60  0000 C CNN
	1    8550 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R23
U 1 1 5EF59318
P 8550 5850
F 0 "R23" V 8550 5750 50  0000 C CNN
F 1 "330" V 8550 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8550 5850 60  0001 C CNN
F 3 "" H 8550 5850 60  0000 C CNN
	1    8550 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	8550 5600 8550 5550
$Comp
L KeyboardParts:LED L15
U 1 1 5EF6B275
P 8850 5350
F 0 "L15" V 8950 5350 50  0000 R CNN
F 1 "1.8mm" V 8650 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 8850 5350 60  0001 C CNN
F 3 "" H 8850 5350 60  0000 C CNN
	1    8850 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R24
U 1 1 5EF6B27B
P 8850 5850
F 0 "R24" V 8850 5750 50  0000 C CNN
F 1 "330" V 8850 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8850 5850 60  0001 C CNN
F 3 "" H 8850 5850 60  0000 C CNN
	1    8850 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	8850 5600 8850 5550
$Comp
L KeyboardParts:LED L16
U 1 1 5EF6B282
P 9150 5350
F 0 "L16" V 9250 5350 50  0000 R CNN
F 1 "1.8mm" V 8950 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 9150 5350 60  0001 C CNN
F 3 "" H 9150 5350 60  0000 C CNN
	1    9150 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R25
U 1 1 5EF6B288
P 9150 5850
F 0 "R25" V 9150 5750 50  0000 C CNN
F 1 "330" V 9150 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 9150 5850 60  0001 C CNN
F 3 "" H 9150 5850 60  0000 C CNN
	1    9150 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	9150 5600 9150 5550
$Comp
L KeyboardParts:LED L17
U 1 1 5EF6B28F
P 9750 5350
F 0 "L17" V 9850 5350 50  0000 R CNN
F 1 "1.8mm" V 9550 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 9750 5350 60  0001 C CNN
F 3 "" H 9750 5350 60  0000 C CNN
	1    9750 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R26
U 1 1 5EF6B295
P 9750 5850
F 0 "R26" V 9750 5750 50  0000 C CNN
F 1 "330" V 9750 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 9750 5850 60  0001 C CNN
F 3 "" H 9750 5850 60  0000 C CNN
	1    9750 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	9750 5600 9750 5550
$Comp
L KeyboardParts:LED L17B1
U 1 1 5EF6B29C
P 10050 5350
F 0 "L17B1" V 10150 5350 50  0000 R CNN
F 1 "1.8mm" V 9850 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 10050 5350 60  0001 C CNN
F 3 "" H 10050 5350 60  0000 C CNN
	1    10050 5350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10050 5600 10050 5550
$Comp
L KeyboardParts:LED L18
U 1 1 5EF6B2A9
P 10350 5350
F 0 "L18" V 10450 5350 50  0000 R CNN
F 1 "1.8mm" V 10150 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 10350 5350 60  0001 C CNN
F 3 "" H 10350 5350 60  0000 C CNN
	1    10350 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R27
U 1 1 5EF6B2AF
P 10350 5850
F 0 "R27" V 10350 5750 50  0000 C CNN
F 1 "330" V 10350 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10350 5850 60  0001 C CNN
F 3 "" H 10350 5850 60  0000 C CNN
	1    10350 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	10350 5600 10350 5550
$Comp
L KeyboardParts:LED L19
U 1 1 5EF9FB07
P 10650 5350
F 0 "L19" V 10750 5350 50  0000 R CNN
F 1 "1.8mm" V 10450 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 10650 5350 60  0001 C CNN
F 3 "" H 10650 5350 60  0000 C CNN
	1    10650 5350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10650 5600 10650 5550
$Comp
L KeyboardParts:LED L20
U 1 1 5EF9FB14
P 10950 5350
F 0 "L20" V 11050 5350 50  0000 R CNN
F 1 "1.8mm" V 10750 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 10950 5350 60  0001 C CNN
F 3 "" H 10950 5350 60  0000 C CNN
	1    10950 5350
	0    -1   -1   0   
$EndComp
$Comp
L KeyboardParts:R R29
U 1 1 5EF9FB1A
P 10950 5850
F 0 "R29" V 10950 5750 50  0000 C CNN
F 1 "330" V 10950 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10950 5850 60  0001 C CNN
F 3 "" H 10950 5850 60  0000 C CNN
	1    10950 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	10950 5600 10950 5550
$Comp
L KeyboardParts:LED L16B1
U 1 1 5EF9FB21
P 9450 5350
F 0 "L16B1" V 9550 5350 50  0000 R CNN
F 1 "1.8mm" V 9250 5350 50  0000 R CNN
F 2 "KeyboardPartsPretty:LED_TH" H 9450 5350 60  0001 C CNN
F 3 "" H 9450 5350 60  0000 C CNN
	1    9450 5350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9450 5600 9450 5550
Wire Wire Line
	4350 5150 4650 5150
Connection ~ 4350 5150
Connection ~ 4650 5150
Wire Wire Line
	4650 5150 4950 5150
Connection ~ 4950 5150
Wire Wire Line
	4950 5150 5250 5150
Connection ~ 5250 5150
Wire Wire Line
	5250 5150 5550 5150
Connection ~ 5550 5150
Wire Wire Line
	5550 5150 5850 5150
Connection ~ 5850 5150
Wire Wire Line
	5850 5150 6150 5150
Connection ~ 6150 5150
Wire Wire Line
	6150 5150 6450 5150
Connection ~ 6450 5150
Connection ~ 7050 5150
Wire Wire Line
	7050 5150 7350 5150
Connection ~ 7350 5150
Connection ~ 8250 5150
Wire Wire Line
	8250 5150 8550 5150
Connection ~ 8550 5150
Wire Wire Line
	8550 5150 8850 5150
Connection ~ 8850 5150
Wire Wire Line
	8850 5150 9150 5150
Wire Wire Line
	9450 5150 9750 5150
Connection ~ 9750 5150
Wire Wire Line
	9750 5150 10050 5150
Connection ~ 10050 5150
Wire Wire Line
	10050 5150 10350 5150
Connection ~ 10350 5150
Wire Wire Line
	10350 5150 10650 5150
Connection ~ 10650 5150
Wire Wire Line
	10650 5150 10950 5150
Wire Wire Line
	9150 5150 9450 5150
Connection ~ 4650 6100
Wire Wire Line
	4650 6100 4350 6100
Connection ~ 4950 6100
Wire Wire Line
	4950 6100 4650 6100
Connection ~ 5250 6100
Wire Wire Line
	5250 6100 4950 6100
Connection ~ 5550 6100
Wire Wire Line
	5550 6100 5250 6100
Connection ~ 5850 6100
Wire Wire Line
	5850 6100 5550 6100
Connection ~ 6150 6100
Wire Wire Line
	6150 6100 5850 6100
Connection ~ 6450 6100
Wire Wire Line
	6450 6100 6150 6100
Connection ~ 7050 6100
Connection ~ 7350 6100
Wire Wire Line
	7350 6100 7050 6100
Connection ~ 8250 6100
Connection ~ 8550 6100
Wire Wire Line
	8550 6100 8250 6100
Connection ~ 8850 6100
Wire Wire Line
	8850 6100 8550 6100
Connection ~ 9150 6100
Wire Wire Line
	9150 6100 8850 6100
Wire Wire Line
	6450 6550 6450 6100
Wire Wire Line
	10650 6100 10350 6100
Connection ~ 10350 6100
$Comp
L KeyboardParts:R R28
U 1 1 5EF9FB0D
P 10650 5850
F 0 "R28" V 10650 5750 50  0000 C CNN
F 1 "330" V 10650 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10650 5850 60  0001 C CNN
F 3 "" H 10650 5850 60  0000 C CNN
	1    10650 5850
	-1   0    0    1   
$EndComp
Wire Wire Line
	6750 5600 6450 5600
Wire Wire Line
	10050 5600 9750 5600
Connection ~ 9750 5600
Wire Wire Line
	9450 5600 9150 5600
Text GLabel 6800 3050 2    50   Input ~ 0
BKL
Connection ~ 7950 5150
Wire Wire Line
	7950 5150 8250 5150
Connection ~ 7950 6100
Wire Wire Line
	7950 6100 8250 6100
Wire Wire Line
	7350 5150 7650 5150
Wire Wire Line
	7350 6100 7650 6100
Connection ~ 7650 5150
Wire Wire Line
	7650 5150 7950 5150
Connection ~ 7650 6100
Wire Wire Line
	7650 6100 7950 6100
Wire Wire Line
	6450 5150 6750 5150
Wire Wire Line
	6450 6100 7050 6100
Connection ~ 6450 5600
Connection ~ 6750 5150
Wire Wire Line
	6750 5150 7050 5150
Connection ~ 9750 6100
Wire Wire Line
	9150 6100 9750 6100
Wire Wire Line
	9750 6100 10350 6100
Connection ~ 9150 5150
Connection ~ 9150 5600
Connection ~ 9450 5150
Wire Wire Line
	10650 6100 10950 6100
Connection ~ 10650 6100
$Comp
L power:VCC #PWR0144
U 1 1 5EF1F953
P 3600 1500
F 0 "#PWR0144" H 3600 1350 50  0001 C CNN
F 1 "VCC" H 3617 1673 50  0000 C CNN
F 2 "" H 3600 1500 50  0001 C CNN
F 3 "" H 3600 1500 50  0001 C CNN
	1    3600 1500
	1    0    0    -1  
$EndComp
Connection ~ 3600 1500
$Comp
L KeyboardParts:KEYSW K12B1
U 1 1 5EBBE17C
P 10750 2850
F 0 "K12B1" H 10750 2850 60  0000 C CNN
F 1 "KEYSW" H 10750 2750 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_2.00u_Vertical_Plate" H 10750 2850 60  0001 C CNN
F 3 "" H 10750 2850 60  0000 C CNN
	1    10750 2850
	-1   0    0    1   
$EndComp
Wire Wire Line
	11050 2650 11050 2850
Connection ~ 11050 2850
Wire Wire Line
	11050 2850 11050 3450
NoConn ~ 6800 2150
$EndSCHEMATC
