![w4CSeq](/html/W4CSEQ_files/w4cseq.png)
# w4CSeq: software and web application to analyze 4C-Seq data

w4CSeq applies a customized pipeline to deal with both enzyme digestion and sonication fragmentation based 4C-Seq data. 
It identifies 4C sites, statistically significant regions, draws interacting plots for intra-chromosomal and inter-chromosomal interactions, and overlays genomic features (TSS, TTS, CpG sites), DNA replication timing and user-provided annotation onto it. 
The combined plots will help uncover significant features in/around 4C regions. 

## Features
* Web server with simple input specification and multiple outputs.
* Users can download the software and install their own servers in a local environment, or use command line to perform analysis.
* Able to analyze 4C-Seq data generated by both enzyme-digestion and sonication-fragmentation methods.

# Usage
## 1. Server
### *demo web server*
* We provide a demo server [w4CSeq](http://w4cseq.wglab.org/) for you to examine. 

### *build your own server*

##### a. Download and Install
Users can download the cutting edge version from GitHub by `git clone git@github.com:WGLab/w4CSeq.git`.

##### b. Software prerequisite
The following softwares should be installed in your cluster before you build server or run w4CSeq command line.
  * R (Packages: RCircos, quantsmooth)
  * Perl (Module: Math::CDF, List::Util)
  * BWA
  * SAMtools
  * BEDTools

##### c. Genome Sequence and Index files prerequisite
In each sub-directory (`hg19`, `hg18`, `mm10`, and `mm9`) under `/w4cseq/lib/`, you need to provide genome sequence and index files (for BWA alignment). For example, under `/w4cseq/lib/hg19/`, you should put the following files: `genome.fa`, `genome.fa.amb`, `genome.fa.ann`, `genome.fa.bwt`, `genome.fa.pac`, `genome.fa.sa` for hg19 assembly. The same applies to `/w4cseq/lib/hg18/`, `/w4cseq/lib/mm10/`, and `/w4cseq/lib/mm9/`. Those files can be easily downloaded from [Illumina iGenomes](http://support.illumina.com/sequencing/sequencing_software/igenome.html).

##### d. Specify paths of softwares in program
  * ##### Enzyme-digestion based 4C-Seq 
    * In `4C_enzyme.R`under `/w4cseq/bin/`, 1) specify the following (`path_w4CSeq`, `path_bwa`, `path_samtools`, `path_bedtools`, `path_RCircos`, `path_quantsmooth`), representing your paths to `w4CSeq`, `BWA`, `SAMtools`, `BEDTools`, `RCircos` and `quantsmooth`; 2) specify your interpreter in the very first `#!` line. 
    * In `Enzyme.cgi` under `/w4cseq/cgi-bin/`, specify the following (`$CARETAKER`, `$SERVER_DIRECTORY`, `$WEBSITE`), representing `email` of housekeeper, path to `w4CSeq`, and assigned website address for your server.

  * ##### Sonication-digestion based 4C-Seq 
    * In `4C_sonication.R`under `/w4cseq/bin/`, 1) specify the following (`path_w4CSeq`, `path_bwa`, `path_samtools`, `path_bedtools`, `path_RCircos`, `path_quantsmooth`); 2) specify your interpreter in the very first `#!` line.
    * In `Sonication.cgi` under `/w4cseq/cgi-bin/`, specify the following (`$CARETAKER`, `$SERVER_DIRECTORY`, `$WEBSITE`).

Once these are set up, the server is ready to go.


## 2. Command line
We recommend you build your own server since it will take input and yield output in an automated manner. Alternatively, you can use one-line command to analyze your 4C-Seq data.

##### a. Complete the `a`, `b`, and `c` steps in `1. Server` section.

##### b. We suggest you perform all analysis under `/w4cseq/work/` directory, and set separate subdirectory to store outputs for each analysis.

  * Enzyme digestion based 4C-Seq data analysis
 
In `4C_enzyme_cmdline.R`under `/w4cseq/bin/`, 1) specify the following (`path_w4CSeq`, `path_bwa`, `path_samtools`, `path_bedtools`, `path_RCircos`, `path_quantsmooth`), representing your paths to `w4CSeq`, `BWA`, `SAMtools`, `BEDTools`, `RCircos` and `quantsmooth`; 2) specify your interpreter in the very first `#!` line. Then run the command line as follows.
```
PATH/TO/w4cseq/bin/4C_enzyme_cmdline.R 1 /PATH/TO/enzyme.fastq.gz hg19 AAGGCAAATTGCCTGAGCTC GAGCTC chr10 104418100 104418600 500 200 5000 enzyme_sample1 no
```
Arguments:
  1. **1**: number of threads. 1 by default and applicable to BWA alignment
  2. **/PATH/TO/enzyme.fastq.gz**: path to the raw fastq file
  3. **hg19**: reference genome
  4. **AAGGCAAATTGCCTGAGCTC**: primer sequence for bait region
  5. **GAGCTC**: recognition sequence for primary restriction enzyme
  6. **chr10**: bait chromosome
  7. **104418100**: starting position of primer pair
  8. **104418600**: ending position of primer pair
  9. **500**: bin size for *trans* chromosome (count of enzyme sites in foreground window)
  10. **200**: bin size for *cis* chromosome (count of enzyme sites in foreground window)
  11. **5000**: window size for *cis* chromosome (count of enzyme sites in background window)
  12. **enzyme_sample1**: working directory name (w4CSeq will automatically generate this folder and all outputs will be generated under ./enzyme_sample1/ directory.)
  13. **no**: whether your data is uncompressed

  * Sonication fragmentation based 4C-Seq data analysis
 
In `4C_sonication_cmdline.R`under `/w4cseq/bin/`, 1) specify the following (`path_w4CSeq`, `path_bwa`, `path_samtools`, `path_bedtools`, `path_RCircos`, `path_quantsmooth`), representing your paths to `w4CSeq`, `BWA`, `SAMtools`, `BEDTools`, `RCircos` and `quantsmooth`; 2) specify your interpreter in the very first `#!` line. Then run the command line as follows.
```
PATH/TO/w4cseq/bin/4C_sonication_cmdline.R 1 /PATH/TO/sonication_1.fastq.gz /PATH/TO/YOUR/FILE/sonication_2.fastq.gz mm10 chr17 35504676 35504824 500 2000000 400000 12000000 sonication_sample1 no
```
Arguments:
  1. **1**: number of threads. 1 by default and applicable to BWA alignment
  2. **/PATH/TO/sonication_1.fastq.gz**: path to the paired end raw fastq files #1
  3. **/PATH/TO/sonication_2.fastq.gz**: path to the paired end raw fastq files #2
  4. **mm10**: reference genome
  5. **chr17**: bait chromosome
  6. **35504676**: starting position of primer pair
  7. **35504824**: ending position of primer pair
  8. **500**: Extended length from end of primer pair to define "bait" neighborhood
  9. **2000000**: bin size for *trans* chromosome (bp length in foreground window)
  10. **400000**: bin size for *cis* chromosome (bp length in foreground window)
  11. **12000000**: window size for *cis* chromosome (bp length in background window)
  12. **sonication_sample1**: working directory name (w4CSeq will automatically generate this folder and all outputs will be generated under ./sonication_sample1/ directory.)
  13. **no**: whether your data is uncompressed

Fore more information on the parameters settings and other, see [here](http://w4cseq.wglab.org).


## Contact
Mingyang Cai

caim@usc.edu


## More
* [w4CSeq Homepage](http://w4cseq.wglab.org)
* [Wang Genomics Lab Homepage](http://genomics.usc.edu)

