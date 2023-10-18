import sys
from config import amplitude

def hex_to_binary(hex: str) -> str:
    binary = ""
    for digit in hex:
        match digit:
            case '0':
                binary += '0000'
            case '0':
                binary += '0000'
            case '1':
                binary += '0001'
            case '2':
                binary += '0010'
            case '3':
                binary += '0011'
            case '4':
                binary += '0100'
            case '5':
                binary += '0101'
            case '6':
                binary += '0110'
            case '7':
                binary += '0111'
            case '8':
                binary += '1000'
            case '9':
                binary += '1001'
            case 'A':
                binary += '1010'
            case 'B':
                binary += '1011'
            case 'C':
                binary += '1100'
            case 'D':
                binary += '1101'
            case 'E':
                binary += '1110'
            case 'F':
                binary += '1111'
            case default:
                raise ValueError(f"Invalid hexadecimal digit: {digit}")
    return binary

def get_signals(filename: str) -> str:
    hex = ""
    with open(filename) as f:
        hex = f.readline().strip().upper()
    try:
        binary = hex_to_binary(hex)
    except ValueError as e:
        print(e)
        sys.exit()
    signals = [(-amplitude) * (-1)**int(bit) for bit in binary]
    return signals
