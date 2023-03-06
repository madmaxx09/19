const fetch = require("node-fetch");
const baseUrl = "https://cf-blast.livelikecdn.com/api/v1";
const cmdArgs = process.argv.slice(2);

let programId = ""

if (cmdArgs[0]) {
    console.log('ProgramId: ', cmdArgs[0])
    programId = cmdArgs[0]

  } else {
    console.log('Syntax: node createAlert "3ffd0e44-b5b7-45ea-a3c9-82b22612fad8"')
    console.log('Syntax: node createAlert "ProgramId"')
    process.exit(1);
  }

  const headers = {
    Accept: "application/json",
    "Content-Type": "application/json",
    Authorization: `Bearer 2hprUkQXepsM9peyvmKHndUPi_CmflDBg2YxpX0mV6SPiqRm1F671w`,
  };

  function delay(time) {
    return new Promise(resolve => setTimeout(resolve, time));
  } 

  const createAlertWidget = async (programId, i) => {

    const url = `${baseUrl}/alerts/`;
   
    let now = new Date()

    console.log('Widget Published:', now)
    let body = {
        program_id: programId,
        title: "Alert Message " + now + "Seq:" + i.toString(),
        text: "TNV HeartBeat " + i.toString(),
        timeout: "P0DT00H00M5S"
    }

    const fetchOptions = {
      method: "POST",
      headers,
      body: JSON.stringify(body)
    };

    const result = await fetch(url, fetchOptions);

    console.log('Status:', result.status)
   
    return await result.json();
}

const scheduleAlert = async(schedule_url, delay) => {

    const url = schedule_url

    publish_delay = "P0DT" + delay.toString() + "S"
    console.log("Delay", publish_delay)
    let body = {publish_delay: publish_delay}
    
    const fetchOptions = {
        method: "PUT",
        headers,
        body: JSON.stringify(body)
      };

      const result = await fetch(url, fetchOptions);

      console.log('Status:', result.status)
      return await result.json()

}

const main = async () => {

    for (let i = 1; i <= 90; i++) {

        let publish_delay = 0   

        const response = await createAlertWidget(programId, i)

        console.log(response.schedule_url)
        let schedule_url = response.schedule_url
        let schedule_response = await scheduleAlert(schedule_url,publish_delay)
        console.log('TNV Heartbeat Alert', i)
        console.log('Publish Schedule at:', schedule_response.scheduled_at)

        await delay(20000);

        
    }

}

main()