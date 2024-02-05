bitset bitset_complement (bitset set){
    bitset complement;
    complement.values = ~set.values & ((1 << set.maxValue) - 1);
    complement.maxValue = set.maxValue;
    return complement;
}