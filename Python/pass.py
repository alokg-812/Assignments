def password():
    passvalue = input()
    count, upper_count, lower_count, digit_count, char_count, seq_count, same_count = 0, 0, 0, 0, 0, 0, 0

    for i in passvalue:
        count += 1
        if i.isupper():
            upper_count += 1
        elif i.islower():
            lower_count += 1
        elif i.isdigit():
            digit_count += 1
        elif (33 <= ord(i) <= 47) or (58 <= ord(i) <= 64) or (91 <= ord(i) <= 96) or (123 <= ord(i) <= 126):
            char_count += 1

    if count < 10:
        print("The password should contain at least ten letters.\nPlease re-enter the password.")
        password()
    elif upper_count < 2:
        print("The password should contain at least two uppercase letters.\nPlease re-enter the password.")
        password()
    elif lower_count < 2:
        print("The password should contain at least two lowercase letters.\nPlease re-enter the password.")
        password()
    elif digit_count < 2:
        print("The password should contain at least two digits.\nPlease re-enter the password.")
        password()
    elif char_count < 2:
        print("The password should contain at least two special characters.\nPlease re-enter the password.")
        password()

    for i in range(len(passvalue)-3):
        if passvalue[i] == passvalue[i+1] == passvalue[i+2] == passvalue[i+3]:
            print("The password should not contain more than three same letters consecutively.\nPlease re-enter the password.")
            password()

    if passvalue in previous:
        print("The password matches the previously set password.\nPlease re-enter the password.")
        password()

    flag = 1
    for i in range(len(username)-2):
        verifier = username[i:i+3]
        for j in range(len(passvalue)-2):
            if passvalue[j:j+3] == verifier:
                flag = 0
                break
        if flag == 0:
            break

    if flag == 1:
        print("Password Verified Successfully!!!")
    else:
        print("The password contains the sequence of three or more consecutive characters from the username.\nPlease re-enter the password.", verifier)
        password()


# Criterias
print("Hi, Welcome to the Password Generator!\nYour password should match the following criteria:\n(1) It must be at least 10 characters long.\n(2) It must contain at least 2 uppercase letters.\n(3) It must contain at least 2 lowercase letters.\n(4) It must contain at least 2 digits.\n(5) It must contain at least 2 special characters.\n(6) It should not contain any sequence of three or more consecutive letters from the username.\n(7) No character should repeat more than three times in a row.\n(8) The new password must not be the same as the previous three passwords.")
# Obtaining username
username = input("Enter the Username: ")
# Obtaining previous passwords
previous = []
a = input("Enter last password: ")
previous.append(a)
b = input("Enter second last password: ")
previous.append(b)
c = input("Enter third last password: ")
previous.append(c)
# Obtaining password
print("Enter the password:")
password()