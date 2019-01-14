class Solution(object):

    def get_small_word(self, num):
        words = ""
        assert num < 1000
        powers = [100, 10, 1]
        power_words = ["Hundred", None, None]

        digits = ["Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                 "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                 "Seventeen", "Eighteen", "Nineteen", "Twenty"]
        tens = [None, None, "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
               "Eighty", "Ninety"]

        i = 0

        # Parse > 100
        if num >= 100:
            q = num/100
            words += digits[q] + " " + "Hundred"
            num = num % 100

        # Parse 20 < num < 100
        if 20 < num < 100:
            q = num/10
            words += " " + tens[q]
            num = num % 10

        # Parse <= 20
        if 1 <= num <= 20:
            words += " " + digits[num]

        return words.strip()



    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return "Zero"

        i = 0
        words = ""
        power_nums = [1000000000, 1000000, 1000, 100]
        power_words = ["Billion", "Million", "Thousand"]
        digits = ["Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]

        while num >= 1000:
            q = num / power_nums[i]
            if q:
                assert q < 1000
                words += " " + self.get_small_word(q) + " " + power_words[i]
                num = num%power_nums[i]
            i += 1

        if num:
            words += " " + self.get_small_word(num)
        return words.strip()
