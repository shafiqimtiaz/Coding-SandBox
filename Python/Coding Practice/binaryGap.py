def solution(N: int) -> int:
    longest_gap = 0
    current_gap = 0
    has_one = False
    while N > 0:
        if N % 2 == 0:
            if has_one:
                current_gap += 1
        else:
            has_one = True
            if current_gap != 0:
                longest_gap = max(longest_gap, current_gap)
                current_gap = 0
        N = N // 2
    return longest_gap
