class Solution:
    def numberToWords(self, num):
        if num == 0:
            return "Zero"

        below_20 = [
            "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
            "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
            "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        ]

        tens = [
            "", "", "Twenty", "Thirty", "Forty", "Fifty",
            "Sixty", "Seventy", "Eighty", "Ninety"
        ]

        def helper(n):
            if n == 0:
                return ""
            elif n < 20:
                return below_20[n] + " "
            elif n < 100:
                return tens[n // 10] + " " + helper(n % 10)
            else:
                return below_20[n // 100] + " Hundred " + helper(n % 100)

        billions = num // 1000000000
        millions = (num // 1000000) % 1000
        thousands = (num // 1000) % 1000
        remainder = num % 1000

        result = ""

        if billions:
            result += helper(billions) + "Billion "
        if millions:
            result += helper(millions) + "Million "
        if thousands:
            result += helper(thousands) + "Thousand "
        if remainder:
            result += helper(remainder)

        return result.strip()