WTP_HOME=/var/wtp
SCRIPT_dir=$(cd $(dirname $0); pwd)
TOP_dir=$(cd $SCRIPT_dir/..; pwd)

cp $TOP_dir/conf/config.wtp $WTP_HOME/
cp $TOP_dir/conf/setting.wtp.txt $WTP_HOME/

cd $TOP_dir
./WTP $WTP_HOME



