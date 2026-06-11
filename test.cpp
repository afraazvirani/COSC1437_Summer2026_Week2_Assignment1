// ============================================================
// Name    : Afraaz Virani
// Course  : COSC 1437 — Programming Fundamentals II
// Date    : 6/8/26
// Program : Chapter 4 Major Project
// Option  : A — Hotel Billing
// Purpose : Creates a hotel billing system that offering discounts, and generatung a relevant billing receipt.
// ============================================================


// ===== Section 1 — Pseudocode Design Block =====
/*
Main Algorithm:
 
1.  Declare real MIN_NIGHTLY_RATE = 0.0
2.  Declare integer MIN_ROOMS = 0
3.  Declare integer MIN_NIGHTS = 0
4.  Declare real MIN_SALES_TAX_RATE = 0.0
5.  Declare real NO_DISCOUNT = 0.0
6.  Declare real DISCOUNT_TIER_ONE = 10.0
7.  Declare real DISCOUNT_TIER_TWO = 20.0
8.  Declare real DISCOUNT_TIER_THREE = 30.0
9.  Declare real LOYALTY_DISCOUNT = 5.0
10. Declare integer MIN_ROOMS_TIER_ONE = 10
11. Declare integer MIN_ROOMS_TIER_TWO = 20
12. Declare integer MIN_ROOMS_TIER_THREE = 30
13. Declare integer MIN_NIGHTS_LOYALTY = 3
14. Declare real EPSILON = 0.01

15. Declare real nightlyRate
16. Declare integer roomsBooked
17. Declare integer nightsStayed
18. Declare real salesTaxRate

19. Print "Enter nightly rate per room: "
20. Input nightlyRate

21. Print "Enter number of rooms booked: "
22. Input roomsBooked

23. Print "Enter number of nights: "
24. Input nightsStayed

25. Print "Enter sales tax rate as a percentage: "
26. Input salesTaxRate
 
Part B

27. if nightlyRate > MIN_NIGHTLY_RATE then
28.       continue
29. else
30.       stop program using assert
31. end if

32. if roomsBooked > MIN_ROOMS then
33.       continue
34. else
35.       stop program using assert
36. end if

37. if nightsStayed > MIN_NIGHTS then
38.       continue
39. else
40.       stop program using assert
41. end if

42. if salesTaxRate >= MIN_SALES_TAX_RATE then
43.       continue
44. else
45.       stop program using assert
46. end if

Part C

47. Show operator precedence table as a comment
48. Show step by step evaluation of the expression "!(rooms > 0) || (rate >= 50.0 && rooms != nights)"

Part D

49. Declare real roomDiscountPercent
50. Declare real loyaltyDiscountPercent
51. Declare real originalSubtotal
52. Declare real roomDiscountAmount
53. Declare real subtotalAfterRoomDiscount
54. Declare real loyaltyDiscountAmount
55. Declare real subtotalBeforeTax
56. Declare integer discountTier
57. Declare real salesTaxAmount
58. Declare real subtotal

59. if roomsBooked >= MIN_ROOMS_TIER_THREE then
60.       roomDiscountPercent = DISCOUNT_TIER_THREE
61.       discountTier = 3
62. else if roomsBooked >= MIN_ROOMS_TIER_TWO then
63.       roomDiscountPercent = DISCOUNT_TIER_TWO
64.       discountTier = 2
65. else if roomsBooked >= MIN_ROOMS_TIER_ONE then
66.       roomDiscountPercent = DISCOUNT_TIER_ONE
67.       discountTier = 1
68. else
69.       roomDiscountPercent = NO_DISCOUNT
70.       discountTier = 0
71. end if

72. if nightsStayed >= MIN_NIGHTS_LOYALTY AND roomsBooked > MIN_ROOMS then
73.       loyaltyDiscountPercent = LOYALTY_DISCOUNT
74. else
75.       loyaltyDiscountPercent = NO_DISCOUNT
76. end if

77. originalSubtotal = nightlyRate * roomsBooked * nightsStayed
78. roomDiscountAmount = originalSubtotal * roomDiscountPercent / 100
79. subtotalAfterRoomDiscount = originalSubtotal - roomDiscountAmount
80. loyaltyDiscountAmount = subtotalAfterRoomDiscount * loyaltyDiscountPercent / 100
81. subtotalBeforeTax = subtotalAfterRoomDiscount - loyaltyDiscountAmount
82. salesTaxAmount = subtotalBeforeTax * salesTaxRate / 100
83. subtotal = subtotalBeforeTax + salesTaxAmount

Part E

84. Print blank line
85. Print "Discount Tier Information"

86. switch discountTier
87.       case 0
88.             Print "Tier 0: No room discount"
89.             Print "Explanation: Fewer than ", MIN_ROOMS_TIER_ONE, " were booked"
90.       case 1
91.             Print "Tier 1: 10% room discount"
92.             Print "Explanation: The customer booked atleast ", MIN_ROOMS_TIER_ONE, " rooms"
93.       case 2
94.             Print "Tier 2: 20% room discount"
95.             Print "Explanation: The customer booked atleast ", MIN_ROOMS_TIER_TWO, " rooms"
96.       case 3
97.             Print "Tier 3: 30% room discount"
98.             Print "Explanation: The customer booked atleast ", MIN_ROOMS_TIER_THREE, " rooms"
99.       default
100.            Print "Tier: Unknown discount tier"
101.            Print "Explanation: Discount Tier could not be determined"
102. end switch

Part F

103. if nightlyRate < MIN_NIGHTLY_RATE then
104.       Print "Error: Nightly Rate is below the allowed minimum"
105. end if

106. if nightsStayed == MIN_NIGHTS then
107.       Print "Error: Nights stayed must be greater than zero"
108. end if

109. if roomsBooked <= MIN_ROOMS then
110.       Print "Error: Rooms booked must be greater than zero"
111. end if

112. if roomDiscountPercent != NO_DISCOUNT then
113.       Print "Check: A room discount was applied"
114. end if

115. if nightlyRate < MIN_NIGHTLY_RATE OR salesTaxRate < MIN_SALES_TAX_RATE then
116.       Print "Error: One of the money related inputs are invalid"
117. end if

118. if NOT subtotalBeforeTax >= 0.0 then
119.       Print "Error: Subtotal is not valid for billing"
120. end if

Part G

121. if absolute value of (subtotalBeforeTax - NO_DISCOUNT) < EPSILON then
122.       Print "Floating-Point Check: Subtotal is close to zero"
123. end if

Part H

124. Format decimal output using fixed and setprecision(2)
125. Print blank line
126. Print "HOTEL BILLING RECEIPT" right aligned in width 30
127. Print blank line
128. Print "Nightly Rate:" left aligned in width 28, "$", nightlyRate right aligned in width 9
129. Print "Room Discount Applied:" left aligned in width 28, roomDiscountPercent right aligned in width 9, "%"
130. Print "Loyalty Discount Applied:" left aligned in width 28, loyaltyDiscountPercent right aligned in width 9, "%"
131. Print "Number of rooms booked:" left aligned in width 28, roomsBooked right aligned in width 10
132. Print "Number of nights booked:" left aligned in width 28, nightsStayed right aligned in width 10
133. Print "---------------------------------------"
134. Print "Subtotal before Tax:" left aligned in width 28, "$", subtotalBeforeTax right aligned in width 9
135. Print "Sales Tax Amount:" left aligned in width 28, "$", salesTaxAmount right aligned in width 9
136. Print "Total Due:" left aligned in width 28, "$", subtotal right aligned in width 9
137. Print "---------------------------------------"

138. return 0
*/


// ===== Program Start =====

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cassert>
#include <cmath>
#include <fstream>
 
using namespace std;
 
int main()
{
    const double MIN_NIGHTLY_RATE = 0.0;
    const int MIN_ROOMS = 0;
    const int MIN_NIGHTS = 0;
    const double MIN_SALES_TAX_RATE = 0.0;
    const double NO_DISCOUNT = 0.0;
    const double DISCOUNT_TIER_ONE = 10.0;
    const double DISCOUNT_TIER_TWO = 20.0;
    const double DISCOUNT_TIER_THREE = 30.0;
    const double LOYALTY_DISCOUNT = 5.0;
    const int MIN_ROOMS_TIER_ONE = 10;
    const int MIN_ROOMS_TIER_TWO = 20;
    const int MIN_ROOMS_TIER_THREE = 30;
    const int MIN_NIGHTS_LOYALTY = 3;
    const double EPSILON = 0.01;


    // ===== Section 2 — Input & Validation =====

    double nightlyRate;
    int roomsBooked;
    int nightsStayed;
    double salesTaxRate;

    cout << "Enter nightly rate per room: ";
    cin >> nightlyRate;

    assert(nightlyRate > MIN_NIGHTLY_RATE);
    // this assert makes sure the nightly rate is greater than zero
    // at runtime, if the user enters zero or a negative value, the program will stop.

    cout << "Enter number of rooms booked: ";
    cin >> roomsBooked;

    assert(roomsBooked > MIN_ROOMS);
    // this assert makes sure the amount of rooms booked is greater than zero
    // at runtime, if the user enters zero or a negative value, the program will stop.
    
    cout << "Enter number of nights: ";
    cin >> nightsStayed;

    assert(nightsStayed > MIN_NIGHTS);
    // this assert makes sure the amount of nights stayed is greater than zero
    // at runtime, if the user enters zero or a negative value, the program will stop.

    cout << "Enter sales tax rate as a percentage: ";
    cin >> salesTaxRate;

    assert(salesTaxRate >= MIN_SALES_TAX_RATE);
    // this assert makes sure the sales text is not negative
    // at runtime, if the user enters a negative value, the program will stop.

    
    
    // ===== Section 3 — Operator Precedence Reference =====
    
    
    /*
    Precedence Table

    Precedence     Operator(s)     Category         Associativity

    1 (highest)    !               Logical NOT      Right-to-left
    2              *, /, %         Multiplicative   Left-to-right
    3              +, -            Additive         Left-to-right
    4              <, <=, >, >=    Relational       Left-to-right
    5              ==, !=          Equality         Left-to-right
    6              &&              Logical AND      Left-to-right
    7              ||              Logical OR       Left-to-right      
    
    
    Step by Step Evaluation
    
    Expression:
    !(rooms > 0) || (rate >= 50.0 && rooms != nights)

    Sample Values:
    roomsBooked = 12
    nightlyRate = 120.0
    nightsStayed = 3

    Evaluation:
    !(12 > 0)  ||  (120.0 >= 50.0 && 12 != 3)
    !(TRUE)    ||  (TRUE && TRUE)
    FALSE      ||  TRUE
    TRUE

    Final Result:
    This expression evaluates to TRUE.
    */

    // ===== Section 4 — Core Logic =====
    double roomDiscountPercent;
    double loyaltyDiscountPercent;
    double originalSubtotal;
    double roomDiscountAmount;
    double subtotalAfterRoomDiscount;
    double loyaltyDiscountAmount;
    double subtotalBeforeTax;
    int discountTier;
    double salesTaxAmount;
    double subtotal;


    // checking the group discount the customer will qualify (30%,20%,10%) based on the amount of rooms booked. 
    if (roomsBooked >= MIN_ROOMS_TIER_THREE)             // Section 6: >= relational operator was used.
    {
        roomDiscountPercent = DISCOUNT_TIER_THREE;
        discountTier = 3;
    }
    else if (roomsBooked >= MIN_ROOMS_TIER_TWO)
    {
        roomDiscountPercent = DISCOUNT_TIER_TWO;
        discountTier = 2;
    }
    else if (roomsBooked >= MIN_ROOMS_TIER_ONE)
    {
        roomDiscountPercent = DISCOUNT_TIER_ONE;
        discountTier = 1;
    }
    else
    {
        roomDiscountPercent = NO_DISCOUNT;
        discountTier = 0;
    }

    // checking whether the customer has atleast three nights AND atleast one room booked to apply the 5% discount.
    if (nightsStayed >= MIN_NIGHTS_LOYALTY && roomsBooked > MIN_ROOMS)       // Section 6: > relational operator was used AND && logical operator was used.
    {
        loyaltyDiscountPercent = LOYALTY_DISCOUNT;
    }
    else
    {
        loyaltyDiscountPercent = NO_DISCOUNT;
    }

    originalSubtotal = nightlyRate * roomsBooked * nightsStayed;
    roomDiscountAmount = originalSubtotal * (roomDiscountPercent / 100);
    subtotalAfterRoomDiscount = originalSubtotal - roomDiscountAmount;
    loyaltyDiscountAmount = subtotalAfterRoomDiscount * (loyaltyDiscountPercent / 100);
    subtotalBeforeTax = subtotalAfterRoomDiscount - loyaltyDiscountAmount;
    

    salesTaxAmount = subtotalBeforeTax * (salesTaxRate / 100);
    subtotal = subtotalBeforeTax + salesTaxAmount;


    // ===== Section 5 — Switch Statement =====
    cout << endl;
    cout << "Discount Tier Information" << endl;

    switch (discountTier)
    {
    case 0:
        cout << "Tier 0: No room discount" << endl;
        cout << "Explanation: Fewer than " << MIN_ROOMS_TIER_ONE << " were booked." << endl;
        break;
    
    case 1:
        cout << "Tier 1: 10% room discount" << endl;
        cout << "Explanation: The customer booked atleast " << MIN_ROOMS_TIER_ONE << " rooms." << endl;
        break;
    
    case 2:
        cout << "Tier 2: 20% room discount" << endl;
        cout << "Explanation: The customer booked atleast " << MIN_ROOMS_TIER_TWO << " rooms." << endl;
        break;
    
    case 3:
        cout << "Tier 3: 30% room discount" << endl;
        cout << "Explanation: The customer booked atleast " << MIN_ROOMS_TIER_THREE << " rooms." << endl;
        break;
    
    default:
        cout << "Tier: Unknown discount tier" << endl;
        cout << "Explanation: Discount Tier could not be determined." << endl;
        break;
    }


    // ===== Section 6 — Relational & Logical Operator Showcase =====

    if (nightlyRate < MIN_NIGHTLY_RATE)  // < relational operator was used
    {
        cout << "Error: Nightly Rate is below the allowed minimum." << endl;
    }

    if (nightsStayed == MIN_NIGHTS)     // == relational operator was used
    {
        cout << "Error: Nights stayed must be greater than zero." << endl;
    }

    if (roomsBooked <= MIN_ROOMS)       // <= relational operator was used
    {
        cout << "Error: Rooms booked must be greater than zero." << endl;
    }

    if (roomDiscountPercent != NO_DISCOUNT)       // != relational operator was used
    {
        cout << "Check: A room discount was applied." << endl;
    }


    if (nightlyRate < MIN_NIGHTLY_RATE || salesTaxRate < MIN_SALES_TAX_RATE)      // || operational operator was used
    {
        cout << "Error: One of the money related inputs are invalid." << endl;
    }

    if (!(subtotalBeforeTax >= 0.0))        // ! operational operator was used
    {
        cout << "Error: Subtotal is not valid for billing." << endl;
    }

    // ===== Section 7 — Floating-Point Bug Guard =====

    /*
    Floating-Point Equality Warning

    Why == is unreliable for floating-point comparison:
    Using == with floating-point values can be unreliable as decimals may be stored with
    tiny rounding errors in memory.

    What technique you used instead (epsilon comparison, tolerance band, or restructured logic):
    Instead of checking whether two money values are exactly equal, this program uses an epsilon comparison. 
    EPSILON is set to 0.01 because this program works with money, and one cent is a reasonable tolerance for billing output.

    The specific epsilon or tolerance value you chose and why:
    The condition below checks whether the calculated subtotal is close enough to zero without comparing subtotalBeforeTax == 0.0.
    */

    if (abs(subtotalBeforeTax - NO_DISCOUNT) < EPSILON)
    {
        cout << "Floating-Point Check: Subtotal is close to zero." << endl;
    }

    // ===== Section 8 — Formatted Output / Receipt =====
    cout << endl;
    cout << fixed << setprecision(2);

    cout << endl;
    cout << right << setw(30) << "HOTEL BILLING RECEIPT" << endl;
    cout << endl;

    cout << left << setw(28) << "Nightly Rate:" << right << "$" << setw(9) << nightlyRate << endl;

    cout << left << setw(28) << "Room Discount Applied:" << right << setw(9) << roomDiscountPercent << "%" << endl;

    cout << left << setw(28) << "Loyalty Discount Applied:" << right << setw(9) << loyaltyDiscountPercent << "%" << endl;

    cout << left << setw(28) << "Number of rooms booked:" << right << setw(10) << roomsBooked << endl;

    cout << left << setw(28) << "Number of nights booked:" << right << setw(10) << nightsStayed << endl;

    cout << "---------------------------------------" << endl;

    cout << left << setw(28) << "Subtotal before Tax:" << right << "$" << setw(9) << subtotalBeforeTax << endl;

    cout << left << setw(28) << "Sales Tax Amount:" << right << "$" << setw(9) << salesTaxAmount << endl;

    cout << left << setw(28) << "Total Due:" << right << "$" << setw(9) << subtotal << endl;

    cout << "---------------------------------------" << endl;


    return 0;
}

    // ===== Section 9 — Known Bug Risks =====
    /*
    1. Dangling else:
    I prevented this by using braces with every if, else if, and else statements.
    This makes it more clear which else belongs to which if statement.

    2. Wrong discount order:
    The loyalty discount must be applied after the room discount, not directly to the original subtotal.
    To prevent this I first calculated subtotalAfterRoomDiscount and then applied the loyalty discount to that amount.
    
    3. Invalid Input:
    Values such as 0 rooms, 0 nights, a negative nightly rate, etc, would make the final bill invalid.
    I prevented this by using assert() checks immediately after reading each input.
    */