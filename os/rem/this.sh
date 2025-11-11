address_book="addressbook.txt"

while true
do
    echo ""
    echo "========= ADDRESS BOOK ========="
    echo "1. Create Address Book"
    echo "2. View Address Book"
    echo "3. Insert a Record"
    echo "4. Delete a Record"
    echo "5. Modify a Record"
    echo "6. Exit"
    echo "================================"
    echo  "Enter your choice [1-6]: "
    read choice

    case $choice in
        1)
            # Create (or clear) address book file
            > $address_book
            echo " Address book created successfully."
            ;;
        2)
            # View address book
            if [ -s "$address_book" ]
            then
                echo "------ ADDRESS BOOK CONTENTS ------"
                cat $address_book
                echo "-----------------------------------"
            else
                echo "Address book is empty or not created."
            fi
            ;;
        3)
            # Insert record
            echo "Enter Name: "
            read name
            echo "Enter Phone: "
            read phone
            echo "Enter Email: "
            read email
            echo "$name | $phone | $email" >> $address_book
            echo " Record added successfully."
            ;;
        4)
            # Delete record
            echo "Enter Name to delete: "
            read name
            grep "^$name" $address_book > temp_found
            if [ -s temp_found ]
            then
                grep -v "^$name" $address_book > temp && mv temp $address_book
                echo " Record deleted successfully."
            elsec
                echo " Record not found."
            fi
            rm -f temp_found
            ;;
        5)
            # Modify record
            echo "Enter Name to modify: "
            read name
            grep "^$name" $address_book > temp_found
            if [ -s temp_found ]
            then
                echo "Enter new Phone: "
                read phone
                echo "Enter new Email: "
                read email
                grep -v "^$name" $address_book > temp
                echo "$name | $phone | $email" >> temp
                mv temp $address_book
                echo " Record modified successfully."
            else
                echo " Record not found."
            fi
            rm -f temp_found
            ;;
        6)
            echo "Exiting program. Goodbye!"
            exit 0
            ;;
        *)
            echo "Invalid choice! Please enter between 1–6."
            ;;
    esac
done


