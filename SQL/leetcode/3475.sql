select
  sample_id,
  dna_sequence,
  species,
  dna_sequence like 'atg%' as has_start,
  (
    dna_sequence like '%taa'
    or dna_sequence like '%tag'
    or dna_sequence like '%tga'
  ) as has_stop,
  dna_sequence like '%atat%' as has_atat,
  dna_sequence like '%ggg%' as has_ggg
from
  samples
order by
  sample_id;
